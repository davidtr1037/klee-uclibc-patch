/*
 * Copyright (C) 2002     Manuel Novoa III
 * Copyright (C) 2000-2005 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include "_string.h"

#ifdef WANT_WIDE
# define Wstrchr wcschr
#else
# define Wstrchr strchr
#endif

libc_hidden_proto(Wstrchr)

Wchar *Wstrchr(register const Wchar *s, Wint c)
{
    unsigned i = 0;
    do {
        if (s[i] == ((Wchar)(c))) {
            return (Wchar *)(s + i);
        }
    } while (s[i++]);
    return NULL;

#if 0
	do {
		if (*s == ((Wchar)c)) {
			return (Wchar *) s;	/* silence the warning */
		}
	} while (*s++);

	return NULL;
#endif
}
libc_hidden_def(Wstrchr)

#if !defined WANT_WIDE && defined __UCLIBC_SUSV3_LEGACY__
strong_alias(strchr,index)
#endif
