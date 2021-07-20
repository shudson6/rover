/*******************************************************************************
 * string.c
 *
 * String functions defined.
 */

#include "string.h"

int strToInt(const char* str) {
  unsigned char multiplier = 1;
  int result = 0;

  while (isSpace(*str)) {
    str++;
  }

  if (*str == '-') {
    multiplier = -1;
    str++;
  }
  if (*str == '+') {
    str++;
  }

  while (isDigit(*str)) {
    result *= 10;
    result += *str - '0';
    str++;
  }

  return result;
}

unsigned char isAlphaNum(char ch) {
  return isAlpha(ch) || isDigit(ch);
}

unsigned char isAlpha(char ch) {
  return isLower(ch) || isUpper(ch);
}

unsigned char isDigit(char ch) {
  return ch >= '0' && ch <= '9';
}

unsigned char isLower(char ch) {
  return ch >= 'a' && ch <= 'z';
}

unsigned char isSpace(char ch) {
  return ch == ' '
      || ch == '\n'
      || ch == '\r'
      || ch == '\t'
      || ch == '\f'
      || ch == '\v';
}

unsigned char isUpper(char ch) {
  return ch >= 'A' && ch <= 'Z';
}

unsigned char isXdigit(char ch) {
  return isDigit(ch)
      || (ch >= 'a' && ch <= 'f')
      || (ch >= 'A' && ch <= 'F');
}
