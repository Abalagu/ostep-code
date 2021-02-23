#include <stdlib.h>
#include <stdio.h>

int main() {
  int *a = malloc(sizeof(int));
  *a = 5;
  printf("a: %d\n", *a);
  free(a);
  printf("free(a) executed.\n");
  printf("value a after free: \n");
  printf("a: %d\n", *a);
  printf("assign value: *a=6\n");
  *a = 6;
  printf("expect crash on printing a\n");
  printf("a: %d\n", *a);
}