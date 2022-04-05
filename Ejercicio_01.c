#include <stdio.h>
#include <stdlib.h>

int length(const char *);
char *copy(char *);
char *string_concat(const char *, const char *);
void string_concat_dynamic(const char *, const char *, char **);
char *char_to_string(char);
void mail_split(const char *, char **, char **);

int main()
{
  char *result = string_concat("Agustin ", "Bernal");
  printf("%s\n", result);

  char *saludo;

  string_concat_dynamic("Hola ", result, &saludo);
  printf("%s\n", saludo);

  char *mail = "ritchie@ansic.com.ar";
  char *user;
  char *dom;
  mail_split(mail, &user, &dom);

  printf("User: %s\tDom:%s\n", user, dom);
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

void string_concat_dynamic(const char *str1, const char *str2, char **buffer)
{
  *buffer = copy(string_concat(str1, str2));
}

char *char_to_string(char c)
{
  char *tmp = malloc(sizeof(char) * 2);
  sprintf(tmp, "%c", c);

  return tmp;
}

void mail_split(const char *mail, char **user, char **dom)
{
  char **temp = malloc(sizeof(char *) * 2);
  temp[0] = "";
  temp[1] = "";

  int i = 0;

  while (mail[i] != '@')
  {
    string_concat_dynamic(temp[0], char_to_string(mail[i]), &temp[0]);
    i++;
  }

  i++;

  while (mail[i] != '\0')
  {
    string_concat_dynamic(temp[1], char_to_string(mail[i]), &temp[1]);
    i++;
  }

  *user = copy(temp[0]);
  *dom = copy(temp[1]);
}
