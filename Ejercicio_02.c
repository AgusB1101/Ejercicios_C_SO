#include "commons/string.h"
#include "commons/txt.h"
#include <stdio.h>
#include <stdlib.h>

void removeLastLineFeed(char *);
char *getLine(FILE *);

int main()
{

  FILE *inputFile = fopen("Personas.txt", "r");

  while (!feof(inputFile))
    printf("%s\n", getLine(inputFile));

  txt_close_file(inputFile);

  return 0;
}

void removeLastLineFeed(char *text)
{
  if (text[string_length(text) - 1] == '\n')
    text[string_length(text) - 2] = '\0';
}

char *getLine(FILE *file)
{
  char *line = string_new();
  int bufSize = 0;
  int lineSize = getline(&line, &bufSize, file);

  removeLastLineFeed(line);

  return line;
}