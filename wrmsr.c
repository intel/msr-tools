#ident "$Id$"
/* ----------------------------------------------------------------------- *
 *   
 *   Copyright 2000 Transmeta Corporation - All Rights Reserved
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, Inc., 675 Mass Ave, Cambridge MA 02139,
 *   USA; either version 2 of the License, or (at your option) any later
 *   version; incorporated herein by reference.
 *
 * ----------------------------------------------------------------------- */

/*
 * wrmsr.c
 *
 * Utility to write to an MSR.
 */

#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <inttypes.h>
#include <sys/types.h>

#include "version.h"

struct option long_options[] = {
  { "help",        0, 0, 'h' },
  { "version",     0, 0, 'V' },
  { "processor",   1, 0, 'p' },
  { "cpu",         1, 0, 'p' },
  { 0, 0, 0, 0 }
};

const char *program;

void usage(void)
{
  fprintf(stderr, "Usage: %s [options] regno value...\n"
	  "  --help         -h  Print this help\n"
	  "  --version      -V  Print current version\n"
	  "  --processor #  -p  Select processor number (default 0)\n"
	  , program);
}

int main(int argc, char *argv[])
{
  uint32_t reg;
  uint64_t data;
  int fd;
  int c;
  int cpu = 0;
  unsigned long arg;
  char *endarg;
  char msr_file_name[64];

  program = argv[0];

  while ( (c = getopt_long(argc,argv,"hVp:",long_options,NULL)) != - 1 ) {
    switch( c ) {
    case 'h':
      usage();
      exit(0);
    case 'v':
      fprintf(stderr, "%s: version %s\n", program, VERSION_STRING);
      exit(0);
    case 'p':
      arg = strtoul(optarg, &endarg, 0);
      if ( *endarg || arg > 255 ) {
	usage();
	exit(127);
      }
      cpu = (int)arg;
      break;
    default:
      usage();
      exit(127);
    }
  }

  if ( optind > argc-2 ) {
    /* Should have at least two arguments */
    usage();
    exit(127);
  }

  reg = strtoul(argv[optind++], NULL, 0);

  sprintf(msr_file_name, "/dev/cpu/%d/msr", cpu);
  fd = open(msr_file_name, O_WRONLY);
  if ( fd < 0 ) {
    if ( errno == ENXIO ) {
      fprintf(stderr, "wrmsr: No CPU %d\n", cpu);
      exit(2);
    } else if ( errno == EIO ) {
      fprintf(stderr, "wrmsr: CPU %d doesn't support MSRs\n", cpu);
      exit(3);
    } else {
      perror("wrmsr:open");
      exit(127);
    }
  }
  
  if ( lseek(fd, reg, SEEK_SET) != reg ) {
    perror("wrmsr:seek");
    exit(127);
  }

  while ( optind < argc ) {
    data = strtouq(argv[optind++], NULL, 0);
    if ( write(fd, &data, sizeof data) != sizeof data ) {
      perror("wrmsr:write");
      exit(127);
    }
  }

  close(fd);

  exit(0);
}

