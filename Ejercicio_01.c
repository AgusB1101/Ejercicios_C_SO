#include <stdio.h>
#include <stdlib.h>

int length(const char *);
char *copy(char *);
char *string_concat(const char *, const char *);

int main()
{
  char *result = string_concat("Agustin ", "Bernal");
  printf("%s\n", result);
}

int length(const char *str)
{
  short i = 0;

  while (str[i] != '\0')
    i++;

  return i;
}

char *copy(char *str)
{
  char *tmp = malloc(sizeof(char) * length(str) + 1);
  sprintf(tmp, "%s", str);
  tmp[length(str)] = '\0';
  return tmp;
}

char *string_concat(const char *str1, const char *str2)
{

  int len1 = length(str1);
  int len2 = length(str2);
  int lenResult = len1 + len2 + 1;

  char *result = malloc(sizeof(char) * lenResult);

  sprintf(result, "%s%s", str1, str2);

  return result;
}