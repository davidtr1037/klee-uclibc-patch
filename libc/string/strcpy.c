/*
 * Copyright (C) 2002     Manuel Novoa III
 * Copyright (C) 2000-2005 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include "_string.h"

#ifdef WANT_WIDE
# define Wstrcpy wcscpy
#else
# define Wstrcpy strcpy
#endif

libc_hidden_proto(Wstrcpy)

Wchar *Wstrcpy(Wchar * __restrict s1, const Wchar * __restrict s2)
{
    unsigned i = 0;
    do {
        s1[i] = s2[i];
    } while (s1[i++] != 0);
    return s1;

#if 0
	register Wchar *s = s1;

#ifdef __BCC__
	do {
		*s = *s2++;
	} while (*s++ != 0);
#else
	while ( (*s++ = *s2++) != 0 );
#endif

	return s1;
#endif
}
libc_hidden_def(Wstrcpy)
