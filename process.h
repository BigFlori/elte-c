#ifndef PROCESS_H
#define PROCESS_H

#include "structs.h"

void processFile(char* filename, struct Options* options);
void processStdin(struct Options* options);

#endif
