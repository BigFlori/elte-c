#ifndef LINE_H
#define LINE_H

#define LINE_BUFFER_SIZE 128

#include <stdio.h>
#include "structs.h"

int readLine(FILE* stream, struct Line* line);
int writeLine(FILE* stream, struct Line* line);
void reverseLine(struct Line* line);

#endif
