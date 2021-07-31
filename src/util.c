/*******************************************************************************
 * util.c
 *
 * Utility functions defined.
 */

#include "util.h"
#include <ctype.h>

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

