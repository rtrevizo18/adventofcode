#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "input.txt"
#define INPUT_FILE_LENGTH 10000
#define NUM_RANGES 60
#define RANGE_CHAR_LENGTH 30

void parse_input(char ranges[NUM_RANGES][2], char input[INPUT_FILE_LENGTH]) {

  char current_range[RANGE_CHAR_LENGTH];
  int range_idx = 0;
  for (int i = 0; input[i] != '\0'; ++i) {

    if (input[i] >= '0' && input[i] <= '9') {
      current_range[range_idx++] = input[i];
    } else if (input[i])
  }
}

int main() {

  FILE *fptr;

  fptr = fopen(INPUT_FILE, "r");

  if (fptr == NULL) {
    printf("Not able to open %s", INPUT_FILE);
    return 1;
  }

  int ranges[NUM_RANGES][2];

  char input[INPUT_FILE_LENGTH];

  fgets(input, INPUT_FILE_LENGTH, fptr);

  parse_input(ranges, input);
}