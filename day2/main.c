#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main() {
  FILE *data;
  // Load file and exit if cannot read
  if ((data = fopen("entry.txt", "r")) == NULL) {
    printf("Error opening entry.txt");
    exit(1);
  }

  // Read the file data line by line
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  int validcount1;
  int validcount2;
  while (getline(&line, &len, data) != -1) {
    char* condition = strtok(line, ":");
    char* string = strtok(NULL, ":");
    char* range = strtok(condition, " ");
    char character = strtok(NULL, " ")[0];
    int start, end;
    extractrange(range, &start, &end);
    int characters = count(string, character);

    // Check for part one
    if (start <= characters && end >= characters) {
      validcount1++;
    }

    // Check for part two
    if ((string[start] == character && string[end] != character) || (string[start] != character && string[end] == character)) {
      validcount2++;
    }
  }
  printf("Part 1 valid passwords: %d\n", validcount1);
  printf("Part 2 valid passwords: %d", validcount2);

  return 0;
}

int count(char* string, char character) {
  int count, i;
  for (i = 0; string[i] != '\0'; i++) {
    if (string[i] == character) {
      count++;
    }
  }

  return count;
}

// Extract the values of the range
void extractrange(char* range, int* start, int* end) {
  char* token = strtok(range, "-");
  *start = atoi(token);
  token = strtok(NULL, "-");
  *end = atoi(token);
}