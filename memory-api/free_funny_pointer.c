#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t s = 100;
  int *a = malloc(s * sizeof(int));
  printf("freeing pointer with offset 20:\n");
  free(a + 20);
}