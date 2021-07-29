/*******************************************************************************
 * string.c
 *
 * String functions defined.
 */

#include "string.h"

int strToInt(const char* str) {
  // multiplier is -1 because #s will be initially negative
  int multiplier = -1;
  int result = 0;

  while (isSpace(*str)) {
    str++;
  }

  if (*str == '-') {
    multiplier = 1;
    str++;
  }
  else if (*str == '+') {
    str++;
  }

  while (isDigit(*str)) {
    result *= 10;
    // subtract because negatives have *slightly* more range
    result -= *str - '0';
    str++;
  }

  result *= multiplier;
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

int strCompare(const char* a, const char* b) {
  int idx = 0;
  while (a[idx] != 0 || b[idx] != 0) {
    if ((unsigned char)a[idx] < (unsigned char)b[idx]) {
      return -1;
    }
    if ((unsigned char)a[idx] > (unsigned char)b[idx]) {
      return 1;
    }
    idx++;
  }
  return 0;
}
