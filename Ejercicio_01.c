#include <stdio.h>
#include <stdlib.h>

int length(const char *);
char *copy(char *);
char *string_concat(const char *, const char *);
void string_concat_dynamic(const char *, const char *, char **);
char *char_to_string(char);
void mail_split(const char *, char **, char **);
char **string_split(const char *, char);
int character_index(const char *, char);

int main()
{
  char *concatenatedString = string_concat("Agustin ", "Bernal");
  printf("%s\n", concatenatedString);

  char *greeting;
  string_concat_dynamic("Hola ", concatenatedString, &greeting);
  printf("%s\n", greeting);

  char *mail = "ritchie@ansic.com.ar";
  char *user;
  char *domain;
  mail_split(mail, &user, &domain);

  printf("User: %s\tDom:%s\n", user, domain);
}

int length(const char *string)
{
  short index = 0;

  while (string[index] != '\0')
    index++;

  return index;
}

char *copy(char *string)
{
  char *result = malloc(sizeof(char) * length(string) + 1);
  sprintf(result, "%s", string);
  result[length(string)] = '\0';
  return result;
}

char *string_concat(const char *str1, const char *str2)
{
  int combinedLength = length(str1) + length(str2) + 1;

  char *result = malloc(sizeof(char) * combinedLength);

  sprintf(result, "%s%s", str1, str2);

  return result;
}

void string_concat_dynamic(const char *str1, const char *str2, char **buffer)
{
  *buffer = copy(string_concat(str1, str2));
}

char *char_to_string(char character)
{
  char *string = malloc(sizeof(char) * 2);
  sprintf(string, "%c", character);

  return string;
}

void mail_split(const char *mail, char **user, char **domain)
{
  char **mailParts = string_split(mail, '@');

  *user = copy(mailParts[0]);
  *domain = copy(mailParts[1]);
}

char **string_split(const char *string, char character)
{
  int sizeOfString = sizeof(char *) * 2;
  char **parts = malloc(sizeOfString);
  parts[0] = "";
  parts[1] = "";
  int dividerIndex = character_index(string, character);
  for (int index = 0; index < length(string); index++)
  {

    char* letter = char_to_string(string[index]);

    if (index < dividerIndex)
      string_concat_dynamic(parts[0], letter, &parts[0]);
    else if (index > dividerIndex)
      string_concat_dynamic(parts[1], letter, &parts[1]);
  }
}

int character_index(const char *string, char character)
{
  int index = 0;

  while (string[index] != character)
    index++;

  return index;
}