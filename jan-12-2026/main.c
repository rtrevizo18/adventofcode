#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "input.txt"
#define INPUT_FILE_LENGTH 5000
#define INPUT_LINE_LENGTH 5

// Goal : number of times the dial is
// left pointing at 0 after any rotation in the sequence

// Parses direction and distance off input
// and decides sign of distance based on direction
int parse_input(char input[INPUT_LINE_LENGTH]) {

  char direction = input[0];

  // skipping over one
  ++input;

  char distance[4];

  int i;

  for (i = 0; i < INPUT_LINE_LENGTH - 1; ++i) {
    distance[i] = *input;
    ++input;
  }

  int new_distance = atoi(distance);

  if (direction == 'L') {
    new_distance *= -1;
  }

  return new_distance;
}

//
int rotate_dial(int start, int distance) {
  int new_dist = start + distance;

  int normalized_distance = new_dist % 100;

  return normalized_distance;
}

int count_zeros(char input[INPUT_FILE_LENGTH][INPUT_LINE_LENGTH]) {
  int count = 0;
  int i = 0;
  int dial_num = 50;

  while (strcmp(input[i], "EOF") != 0) {

    int parsed_distance = parse_input(input[i]);

    dial_num = rotate_dial(dial_num, parsed_distance);

    if (dial_num == 0) {
      ++count;
    }
    ++i;
  }

  return count;
}

int main() {

  FILE *fptr;

  fptr = fopen(INPUT_FILE, "r");

  if (fptr == NULL) {
    printf("Not able to open %s", INPUT_FILE);
    return 1;
  }

  char input_array[INPUT_FILE_LENGTH][INPUT_LINE_LENGTH];

  int i = 0;

  while (fgets(input_array[i], INPUT_LINE_LENGTH, fptr)) {
    input_array[i][strcspn(input_array[i], "\n")] = 0;
    i++;
  }

  fclose(fptr);

  // Signal end of array
  strcpy(input_array[i], "EOF");

  int result = count_zeros(input_array);

  printf("Count: %d\n", result);

  return 0;
}
