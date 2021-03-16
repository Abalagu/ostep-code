#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  int fd = open("~/CLionProjects/ostep-code/cpu-api/dummy.txt", O_APPEND, mode);
  if (fd == -1) {
    fprintf(stderr, "open failed\n");
    exit(1);
  }
  printf("fd open: %d\n", fd);
  char buffer[] = "something";
  write(fd, buffer, strlen(buffer));
  close(fd);
}