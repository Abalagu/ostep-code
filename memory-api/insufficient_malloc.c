#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  char *src = "hello";
  char *dst = (char *) malloc(strlen(src));
  printf("execute strcpy(dst, src);, expect no fault with wrong code.\n");
  printf("should allocate one more byte for terminating char.\n");
  strcpy(dst, src);
  printf("no fault occurs.\n");
}