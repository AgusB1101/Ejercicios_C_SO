#include "commons/string.h"
#include "commons/txt.h"
#include <stdio.h>
#include <stdlib.h>

void removeLastLineFeed(char *);
char *getLine(FILE *);
int occurrencesOfChar(char *, char);
int fieldsAmount(char *);
char **getFields(char *);

int main()
{

  FILE *inputFile = fopen("Personas.txt", "r");

  char *line = getLine(inputFile);
  char **personFields = getFields(line);

  for (int i = 0; i < fieldsAmount(line); i++)
    puts(personFields[i]);

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

int occurrencesOfChar(char *string, char character)
{
  int counter = 0;

  for (int i = 0; i < string_length(string); i++)
    if (string[i] == character)
      counter++;

  return counter;
}

int fieldsAmount(char *string)
{
  return occurrencesOfChar(string, ';') + 1;
}

char **getFields(char *string)
{
  return string_n_split(string, fieldsAmount(string), "; ");
}