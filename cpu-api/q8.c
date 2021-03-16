#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main() {
  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(1);
  }

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "error.\n");
    exit(1);
  } else if (rc == 0) { // first child
    printf("hello from first child pid: %d\n", getpid());
    char buf[] = "this is what first child writes.\n";
    write(pipefd[1], buf, strlen(buf));
  } else {
    rc = fork();
    if (rc < 0) {
      fprintf(stderr, "error when fork second child.\n");
    } else if (rc == 0) { // second child
      printf("hello from second child pid: %d.\n", getpid());
      char *read_buffer = calloc(100, sizeof(char));
      while (read(pipefd[0], read_buffer, 50) == 0) {
      }
      printf("second child read in: \n%s\n", read_buffer);
    } else {
      printf("hello from parent after creating second child.\n");
    }
  }
  return 0;
}