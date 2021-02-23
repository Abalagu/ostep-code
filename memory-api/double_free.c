#include <stdlib.h>
#include <stdio.h>

int main() {
  int *a = malloc(10 * sizeof(int));
  printf("first free: \n");
  free(a);
  printf("second free: \n");
  free(a);
  printf("second free executed.\n");
}