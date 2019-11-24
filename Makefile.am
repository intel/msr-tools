AM_CFLAGS = -Wall -g -O2 -fomit-frame-pointer \
	-D_GNU_SOURCE -D_FILE_OFFSET_BITS=64

sbin_PROGRAMS = wrmsr rdmsr msr-cpuid
man8_MANS = wrmsr.8 rdmsr.8 msr-cpuid.8

wrmsr_SOURCES =		\
	wrmsr.c		\
	version.h

wrmsr_CFLAGS = $(AM_CFLAGS)

rdmsr_SOURCES =		\
	rdmsr.c		\
	version.h

rdmsr_CFLAGS = $(AM_CFLAGS)

msr_cpuid_SOURCES =		\
	cpuid.c

msr_cpuid_CFLAGS = $(AM_CFLAGS)
