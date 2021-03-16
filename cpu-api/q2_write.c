#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
  int fd = open("./dummy.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
  printf("fd: %d\n", fd);
  char buffer[] = "this is the first line\n";
  write(fd, buffer, strlen(buffer));
  int rc = fork();
  if (rc < 0) {
    printf("fork failed\n");
  } else if (rc == 0) {
    printf("this is child\n");
    char buffer[] = "line from child\n";
    write(fd, buffer, strlen(buffer));
    close(fd);
  } else {
    printf("this is parent\n");
    char buffer[] = "line from parent\n";
    write(fd, buffer, strlen(buffer));
    close(fd);
  }
  return 0;
}