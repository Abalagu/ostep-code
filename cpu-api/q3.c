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
    printf("hello\n");
  } else {
    int wc = wait(NULL);
    printf("goodbye\n");
  }
}