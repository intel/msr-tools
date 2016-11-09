AC_PREREQ([2.69])
AC_INIT([msr-tools], [1.3.0], [https://01.org/msr-tools])
AM_INIT_AUTOMAKE([1.14 -Wall -Werror -Wno-extra-portability foreign no-dist-gzip dist-zip])
AM_SILENT_RULES([yes])
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([cpuid.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for header files.
AC_CHECK_HEADERS([ctype.h])
AC_CHECK_HEADERS([dirent.h])
AC_CHECK_HEADERS([errno.h])
AC_CHECK_HEADERS([fcntl.h])
AC_CHECK_HEADERS([getopt.h])
AC_CHECK_HEADERS([inttypes.h])
AC_CHECK_HEADERS([stdbool.h])
AC_CHECK_HEADERS([stdint.h])
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([sys/types.h])
AC_CHECK_HEADERS([unistd.h])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT

AC_MSG_RESULT([
        msr-tools $VERSION
        ========

        prefix:                 ${prefix}
        bindir:                 ${bindir}

        compiler:               ${CC}
        cflags:                 ${CFLAGS}
        ldflags:                ${LDFLAGS}
])
