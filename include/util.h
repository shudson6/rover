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

/*******************************************************************************
 * unsigned char isNumeric(const char* str)
 *
 * Determines whether str points to a valid string representation of an integer.
 * Like strToInt(), leading whitespace is ignored and a leading sign is allowed.
 * Unlike strToInt(), trailing characters are not allowed; once a digit is
 * encountered in the string, any nondigit found before the null terminator will
 * result in a return of zero.
 * This function does not guarantee the value represented will fit any integral
 * type.
 *
 * Returns nonzero if the string represents an integer.
 * Returns zero otherwise.
 */
unsigned char isNumeric(const char* str);

/*******************************************************************************
 * unsigned char fitsInt16(const char* str)
 *
 * Determines whether the base-10 integer represented in str will fit in a 
 * 16-bit signed integer, using the same parsing rules as strToInt(). This is 
 * meant to check if the value returned by strToInt() will be reliable.
 *
 * Returns nonzero if str represents an integer that will fit in a signed int16.
 * Returns zero otherwise.
 */
unsigned char fitsInt16(const char* str);
