#include "line.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readLine(FILE* stream, struct Line* line) {
  char buffer[LINE_BUFFER_SIZE];
  if (fgets(buffer, LINE_BUFFER_SIZE, stream) == NULL) {
    return EOF;
  } else {
    size_t len = strcspn(buffer, "\r\n");
    buffer[len] = '\0';
    if (strlen(buffer) == LINE_BUFFER_SIZE - 1) {
      int c = fgetc(stream);
      while (c != EOF && c != '\n' && c != '\r') {
        c = fgetc(stream);
      }
    }
  }

  int length = strlen(buffer);
  line->text = malloc((length + 1) * sizeof(char));
  strcpy(line->text, buffer);

  return 0;
}

int writeLine(FILE* stream, struct Line* line) {
  return fputs(line->text, stream) == EOF ? EOF : 0;
}

void reverseLine(struct Line* line) {
  int length = strlen(line->text);
  for (int i = 0; i < length / 2; i++) {
    char tmp = line->text[i];
    line->text[i] = line->text[length - i - 1];
    line->text[length - i - 1] = tmp;
  }
}
