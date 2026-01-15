#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "input.txt"
#define INPUT_FILE_LENGTH 10000
#define NUM_RANGES 60
#define RANGE_CHAR_LENGTH 30

int is_palindrome(char *string, int n) {
  for (int i = 0; i < n / 2; ++i) {
    if (string[i] != string[n - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int process_ranges(char start_range[RANGE_CHAR_LENGTH],
                   char end_range[RANGE_CHAR_LENGTH]) {
  char *temp;
  unsigned long long start = strtoll(start_range, &temp, 10);
  printf("%llu - ", start);
  unsigned long long end = strtoll(end_range, &temp, 10);
  printf("%llu \n", end);
  return 0;
}

int main() {

  FILE *fptr;

  fptr = fopen(INPUT_FILE, "r");

  if (fptr == NULL) {
    printf("Not able to open %s", INPUT_FILE);
    return 1;
  }

  char ch;
  char start_range[RANGE_CHAR_LENGTH];
  int start_range_idx = 0;
  char end_range[RANGE_CHAR_LENGTH];
  int end_range_idx = 0;
  int start_or_end = 0; // 0 for start, 1 for end

  while (ch = fgetc(fptr)) {
    if (ch == '-') {
      start_or_end = 1;
    } else if (ch == ',' || ch == EOF) {
      process_ranges(start_range, end_range);
      start_range_idx = 0;
      end_range_idx = 0;
      start_range[0] = '\0';
      end_range[0] = '\0';
      start_or_end = 0;
      if (ch == EOF) {
        break;
      }
    } else if (ch >= '0' && ch <= '9') {
      if (start_or_end == 0) {
        start_range[start_range_idx++] = ch;
      } else {
        end_range[end_range_idx++] = ch;
      }
    } else {
      printf("Undefined character in input: '%c', terminating...", ch);
      return 1;
    }
  }
}