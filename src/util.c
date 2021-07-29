/*******************************************************************************
 * util.c
 *
 * Utility functions defined.
 */

#include "util.h"
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

