#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int *x = malloc(10 * sizeof(int));
  printf("init as int *x\n");
  printf("sizeof(x): %ld\n\n", sizeof(x));

  int y[10];
  printf("init as int y[10]\n");
  printf("sizeof(y): %ld\n\n", sizeof(y));

  char a[] = "abcdefg";
  printf("init as char a[]\n");
  printf("a: %s\n", a);
  printf("sizeof(a): %ld\n\n", sizeof(a));

  char *b = "defghi";
  printf("init as char *b\n");
  printf("b: %s\n", b);
  printf("sizeof(b): %ld\n\n", sizeof(b)); // CLion prompts this usage as suspicious

  char c[10];
  printf("init as char c[10]\n");
  printf("sizeof(c): %ld\n\n", sizeof(c));

  char *d = malloc(strlen("abcdefghhhhhh")+1);
  printf("d: %s\n", d);
  printf("sizeof(d): %ld\n\n", sizeof(d));
}