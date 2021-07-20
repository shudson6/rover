/*******************************************************************************
 * string.c
 *
 * String functions defined.
 */

#include "string.h"

int atoi(const char* str) {
  unsigned char multiplier = 1;
  int result = 0;

  while (isspace(*str)) {
    str++;
  }

  if (*str == '-') {
    multiplier = -1;
    str++;
  }
  if (*str == '+') {
    str++;
  }

  while (isdigit(*str)) {
    result *= 10;
    result += *str - '0';
    str++;
  }

  return result;
}

unsigned char isalnum(char ch) {
  return isalpha(ch) || isdigit(cd);
}

unsigned char isalpha(char ch) {
  return islower(ch) || isupper(ch);
}

unsigned char isdigit(char ch) {
  return ch >= '0' && ch <= '9';
}

unsigned char islower(char ch) {
  return ch >= 'a' && ch <= 'z';
}

unsigned char isspace(char ch) {
  return ch == ' '
      || ch == '\n'
      || ch == '\r'
      || ch == '\t'
      || ch == '\f'
      || ch == '\v';
}

unsigned char isupper(char ch) {
  return ch >= 'A' && ch <= 'Z';
}

unsigned char isxdigit(char ch) {
  return isdigit(ch)
      || (ch >= 'a' && ch <= 'f')
      || (ch >= 'A' && ch <= 'F');
}
