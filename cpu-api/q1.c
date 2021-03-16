#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int x = 100;
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello, this is child (pid:%d)\n", (int) getpid());
    printf("value x in child: %d\n", x);
    x += 5;
    printf("value x in child (after): %d\n", x);
  } else {
    printf("hello, this is parent (pid:%d), of child (pid:%d)\n", (int) getpid(), rc);
    printf("value x in parent: %d\n", x);
    x += 10;
    printf("value x in parent (after): %d\n", x);
  }
  return 0;
}