/*
 * Copyright (C) 2002     Manuel Novoa III
 * Copyright (C) 2000-2005 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include "_string.h"

#ifdef WANT_WIDE
# define Wstrrchr wcsrchr
#else
libc_hidden_proto(strrchr)
# define Wstrrchr strrchr
#endif

Wchar *Wstrrchr(register const  Wchar *s, Wint c)
{
    size_t n = strlen(s);
    for (unsigned i = 0; i < n; i++) {
        const Wchar *p = s + (n - i - 1);
        if (*p == c) {
            return (Wchar *)(p);
        }
    }
    return NULL;

#if 0
	register const Wchar *p;

	p = NULL;
	do {
		if (*s == (Wchar) c) {
			p = s;
		}
	} while (*s++);

	return (Wchar *) p;			/* silence the warning */
#endif
}
#ifndef WANT_WIDE
libc_hidden_def(strrchr)
# ifdef __UCLIBC_SUSV3_LEGACY__
strong_alias(strrchr,rindex)
# endif
#endif
