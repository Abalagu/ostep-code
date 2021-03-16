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
    int child_wait_ret = wait(NULL);
    printf("child wait ret: %d\n", child_wait_ret);
  } else {
    int ret = wait(NULL);
    printf("goodbye\n");
    printf("parent wait ret: %d\n", ret);
  }
}