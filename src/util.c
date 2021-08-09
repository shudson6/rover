/*******************************************************************************
 * util.c
 *
 * Utility functions defined.
 */

#include "util.h"
#include <ctype.h>
#include <string.h>

int strToInt(const char* str) {
  // multiplier is -1 because #s will be initially negative
  int multiplier = -1;
  int result = 0;

  while (isspace(*str)) {
    str++;
  }

  if (*str == '-') {
    multiplier = 1;
    str++;
  }
  else if (*str == '+') {
    str++;
  }

  while (isdigit(*str)) {
    result *= 10;
    // subtract because negatives have *slightly* more range
    result -= *str - '0';
    str++;
  }

  result *= multiplier;
  return result;
}

unsigned char isNumeric(const char* str) {
  while (isspace(*str)) {
    str++;
  }

  if (*str == '-' || *str == '+') {
    str++;
  }

  // need at least one digit to be valid
  // if the next nondigit character is the null terminator, it's good.
  if (isdigit(*str)) {
    while (isdigit(*str)) {
      str++;
    }
    if (*str == 0) {
      return 1;
    }
  }

  return 0;
}

static const char DIGITS_MAX16[] = "32767";
static const char DIGITS_MIN16[] = "32768";

unsigned char fitsInt16(const char* str) {
    while (isspace(*str)) {
      str++;
    }

    unsigned char isNegative = 0;
    if (*str == '-') {
      str++;
      isNegative = 1;
    }
    else if (*str == '+') {
      str++;
    }

    const char *strEnd = str;
    while (isdigit(*strEnd)) {
      strEnd++;
    }

    if (strEnd == str) {
      return 0;
    }
    else if (strEnd - str > 5) {
      return 0;
    }
    else if (strEnd - str < 5) {
      return 1;
    }

    const char *digits = (isNegative) ? DIGITS_MIN16 : DIGITS_MAX16;
    int cmp = strncmp(str, digits, 5);
    return cmp <= 0;
}

