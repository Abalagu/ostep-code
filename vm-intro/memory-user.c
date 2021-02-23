//
// Created by xuluming on 2/23/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MiB * (0x1<<20)


int main(int argc, char *argv[]) {
  int base = 10;
  char *endptr, *str;
  long val;
  char *array;

  if (argc != 2) {
    printf("usage: memory-user <memory size>\n");
    printf("give memory size in MiB\n");
    exit(EXIT_FAILURE);
  }
  str = argv[1];
  errno = 0;
  val = strtol(argv[1], &endptr, base);
  if (errno != 0) {
    perror("strtol");
    exit(EXIT_FAILURE);
  }
  if (endptr == str) {
    fprintf(stderr, "No digits were found\n");
    exit(EXIT_FAILURE);
  }

  printf("Allocate memory of size: %ld MiB\n", val);
  array = malloc(val MiB);
  while (1) {
    for (int i = 0; i < val MiB; i++) {
      array[i] = 1;
    }
  }


  printf("allocated and written to array\n");
  printf("head: %ld, tail: %ld\n", (long) array[0], (long) array[val MiB - 1]);

}
