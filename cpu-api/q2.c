#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  int fd = open("./Makefile", O_RDONLY);
  printf("fd: %d\n", fd);
  char *buffer = (char *) calloc(100, sizeof(char));

  int rc = fork();
  if (rc < 0) {
    printf("fork failed\n");
  } else if (rc == 0) {
    printf("this is child\n");
    read(fd, buffer, 30);
    printf("child buffer: %s\n", buffer);
  } else {
    printf("this is parent\n");
    read(fd, buffer, 30);
    printf("parent buffer: %s\n", buffer);
  }
  return 0;
}