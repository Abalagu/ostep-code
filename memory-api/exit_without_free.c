#include <stdlib.h>
#include <stdio.h>

int main() {
  int *a = malloc(10 * sizeof(int));
  printf("exit without freeing int array *a\n");
}