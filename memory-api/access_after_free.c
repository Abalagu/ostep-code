#include <stdlib.h>
#include <stdio.h>

int main() {
  size_t s = 10;
  int *a = malloc(s * sizeof(int));
  for (int i = 0; i < s; i++) {
    a[i] = i;
  }
  for (int i = 0; i < s; i++) {
    printf("a[%d]=%d\n", i, a[i]);
  }

  free(a);
  printf("array a freed.  trying to access element in array a: \n");
  printf("expect exception: \n");
  for (int i = 0; i < s; i++) {
    printf("a[%d]=%d\n", i, a[i]);
  }

}