/*******************************************************************************
 * util.h
 *
 * Miscellaneous utility functions needed for the project.
 */

/*******************************************************************************
 * int strToInt(const char* str)
 *
 * Converts a string to an integer. Leading whitespace is ignored. As many
 * characters as form a valid integer are processed into an int. Any trailing
 * characters are ignored. If no conversion is possible, zero is returned. If
 * the represented value is larger than fits in an int, return value is 
 * undefined.
 */
int strToInt(const char* str);

