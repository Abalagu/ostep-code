#include <stdio.h>
#include <string.h>

int main() {
  char *src = "hello";
  char *dst;
  printf("execute strcpy(dst, src);, expect segmentation fault.\n");
  strcpy(dst, src);
}