#include "commons/string.h"
#include "commons/txt.h"
#include <stdio.h>
#include <stdlib.h>

char *char_to_string(char);
char *getFileText(FILE *);

int main()
{

  FILE *inputFile = fopen("Personas.txt", "r");

  char *fileText = getFileText(inputFile);

  printf("%s\n", fileText);

  txt_close_file(inputFile);

  return 0;
}

char *char_to_string(char character)
{
  return string_from_format("%c", character);
}

char *getFileText(FILE *file)
{
  char *fileText = string_new();

  while (!feof(file))
    string_append(&fileText, char_to_string(fgetc(file)));

  return fileText;
}