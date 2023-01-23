#include "process.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 8
#define BUFFER_MULTIPLIER 2

void processFile(char* filename, struct Options* options) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "File opening unsuccessful: %s\n", filename);
    return;
  }

  struct Line* lines = malloc(INITIAL_BUFFER_SIZE * sizeof(struct Line));
  if (lines == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  int numLines = 0;
  int bufferSize = INITIAL_BUFFER_SIZE;

  struct Line line;
  line.maxLineLength = options->maxLineLength;
  while (readLine(file, &line) == 0) {
    if (numLines == bufferSize) {
      bufferSize *= BUFFER_MULTIPLIER;
      lines = realloc(lines, bufferSize * sizeof(struct Line));
      if (lines == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
      }
    }
    lines[numLines++] = line;
  }

  for (int i = numLines - 1; i >= 0; i--) {
    if (options->showLineNumbers) {
      printf("%d ", i + 1);
    }
    reverseLine(&lines[i]);
    printf("%s\n", lines[i].text);
    free(lines[i].text);
  }

  free(lines);
  fclose(file);
}

void processStdin(struct Options* options) {
  struct Line* lines = malloc(INITIAL_BUFFER_SIZE * sizeof(struct Line));
  if (lines == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  int numLines = 0;
  int bufferSize = INITIAL_BUFFER_SIZE;

  struct Line line;
  line.maxLineLength = options->maxLineLength;
  while (readLine(stdin, &line) == 0) {
    if (numLines == bufferSize) {
      bufferSize *= BUFFER_MULTIPLIER;
      lines = realloc(lines, bufferSize * sizeof(struct Line));
      if (lines == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
      }
    }
    lines[numLines++] = line;
  }

  for (int i = numLines - 1; i >= 0; i--) {
    if (options->showLineNumbers) {
      printf("%d ", i + 1);
    }
    reverseLine(&lines[i]);
    printf("%s\n", lines[i].text);
    free(lines[i].text);
  }

  free(lines);
}