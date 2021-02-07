/*
 * Copyright (C) 2002     Manuel Novoa III
 * Copyright (C) 2000-2005 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include "_string.h"

#ifdef WANT_WIDE
# define Wstrspn wcsspn
#else
# define Wstrspn strspn
#endif

libc_hidden_proto(Wstrspn)

size_t Wstrspn(const Wchar *s1, const Wchar *s2)
{
	register unsigned i = 0;
	register const Wchar *p = s2;
	while (*p) {
		if (*p++ == s1[i]) {
			++i;
			p = s2;
		}
	}
	return i;

#if 0
	register const Wchar *s = s1;
	register const Wchar *p = s2;

	while (*p) {
		if (*p++ == *s) {
			++s;
			p = s2;
		}
	}
	return s - s1;
#endif
}
libc_hidden_def(Wstrspn)
