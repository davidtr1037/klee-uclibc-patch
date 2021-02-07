/*
 * Copyright (C) 2002     Manuel Novoa III
 * Copyright (C) 2000-2005 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include "_string.h"

#ifdef WANT_WIDE
# define Wstrlen wcslen
#else
# define Wstrlen strlen
#endif

libc_hidden_proto(Wstrlen)

size_t Wstrlen(const Wchar *s)
{
	register unsigned i;
	for (i = 0 ; s[i]; i++) {

	}
	return i;

#if 0
	register const Wchar *p;

	for (p=s ; *p ; p++);

	return p - s;
#endif
}
libc_hidden_def(Wstrlen)
