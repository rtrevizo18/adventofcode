#include <stdio.h>

#define INPUT_FILE "input2.txt"

int main() {

  FILE *fptr;

  fptr = fopen(INPUT_FILE, "r");

  if (fptr != NULL) {
    printf("Hey, this file %s doesn't exist, wth!!??", INPUT_FILE);
  }

  fclose(fptr);

  return 0;
}