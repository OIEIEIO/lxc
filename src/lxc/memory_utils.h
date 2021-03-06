/* liblxcapi
 *
 * Copyright © 2019 Christian Brauner <christian.brauner@ubuntu.com>.
 * Copyright © 2019 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __LXC_MEMORY_UTILS_H
#define __LXC_MEMORY_UTILS_H

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

static inline void __auto_free__(void *p)
{
	free(*(void **)p);
}

static inline void __auto_fclose__(FILE **f)
{
	if (*f)
		fclose(*f);
}

static inline void __auto_closedir__(DIR **d)
{
	if (*d)
		closedir(*d);
}

#define __do_free __attribute__((__cleanup__(__auto_free__)))
#define __do_fclose __attribute__((__cleanup__(__auto_fclose__)))
#define __do_closedir __attribute__((__cleanup__(__auto_closedir__)))

#endif /* __LXC_MEMORY_UTILS_H */
