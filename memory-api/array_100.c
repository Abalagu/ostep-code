#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t s = 100;
  int *data = malloc(s * sizeof(int));
  printf("setting data[100]=0\n");
  printf("writing to memory outside allocation.\n");
  data[100] = 0;
}