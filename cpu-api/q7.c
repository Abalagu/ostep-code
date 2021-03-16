#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "error.\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello from child pid: %d\n", getpid());
    close(STDOUT_FILENO);
    printf("call after closing stdout");
  } else {
    printf("hello from parent\n");
  }
}