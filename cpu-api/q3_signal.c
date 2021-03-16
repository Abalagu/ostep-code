#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  int rc = fork();
  int parent_pid = getpid();
  if (rc < 0) {
    fprintf(stderr, "error.\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello\n");
    kill(parent_pid, SIGCONT);
  } else {
    printf("parent before stop\n");
    kill(getpid(), SIGSTOP);
    printf("goodbye\n");
  }
  return 0;
}