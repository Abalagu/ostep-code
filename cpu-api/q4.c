#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  printf("execl\n");
  int ret_execl = execl("/bin/ls", "ls", "-l", NULL);
  printf("exelp\n");
  int ret_execlp = execlp("./dummy_shell.sh", "/bin/sh", NULL);
}