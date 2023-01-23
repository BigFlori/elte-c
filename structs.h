#ifndef STRUCTS_H
#define STRUCTS_H

struct Options {
  int showLineNumbers;
  int maxLineLength;
};

struct Line {
  int maxLineLength;
  char* text;
};

#endif
