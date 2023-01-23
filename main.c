#include "process.h"
#include "line.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  struct Options options;
  if (argc < 3) {
    printf("Usage:\n\trev [SHOW LINE NUMBERS] [MAX LINE LENGTH] files...\n");
    return 1;
  } else if (strcmp(argv[1], "linenums") == 0) {
    options.showLineNumbers = 1;
  } else if (strcmp(argv[1], "nolinenums") == 0) {
    options.showLineNumbers = 0;
  } else {
    printf("Usage:\n\trev [SHOW LINE NUMBERS] [MAX LINE LENGTH] files...\n");
    return 1;
  }
  options.maxLineLength = atoi(argv[2]);

  for (int i = 3; i < argc; i++) {
    processFile(argv[i], &options);
  }

  if (argc == 3) {
    processStdin(&options);
  }

  return 0;
}
