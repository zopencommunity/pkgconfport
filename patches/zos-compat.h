/*
 * z/OS compatibility shims for the pkgconf port.
 *
 * On z/OS, EXIT_FAILURE is defined as 8 (matching the ABEND/signal
 * convention) rather than the POSIX-conventional 1.  The pkgconf test
 * suite — and essentially all POSIX-oriented consumers — expect error
 * exits to produce code 1, so we redefine EXIT_FAILURE here.
 *
 * This header is injected into every translation unit via
 *   -include patches/zos-compat.h
 * in ZOPEN_EXTRA_CPPFLAGS (see buildenv).
 */

#ifndef ZOS_COMPAT_H
#define ZOS_COMPAT_H

#ifdef __MVS__
# include <stdlib.h>   /* pull in the system definition first */
# undef  EXIT_FAILURE
# define EXIT_FAILURE 1
#endif

#endif /* ZOS_COMPAT_H */
