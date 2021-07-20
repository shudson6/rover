/*******************************************************************************
 * string.h
 *
 * String functions needed for the project.
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
 * unsigned char isAlphaNum(char ch)
 *
 * Returns nonzero if ch is an alphanumeric character or zero if not.
 */
unsigned char isAlphaNum(char ch);

/*******************************************************************************
 * unsigned char isAlpha(char ch)
 *
 * Returns nonzero if ch is an alphabet character or zero if not.
 */
unsigned char isAlpha(char ch);

/*******************************************************************************
 * unsigned char isDigit(char ch)
 *
 * Returns nonzero if ch is a digit [0-9] character or zero if not.
 */
unsigned char isDigit(char ch);

/*******************************************************************************
 * unsigned char isLower(char ch)
 *
 * Returns nonzero if ch is a lowercase letter character or zero if not.
 */
unsigned char isLower(char ch);

/*******************************************************************************
 * unsigned char isSpace(char ch)
 *
 * Returns nonzero if ch is a whitespace character (space, tab, newline, 
 * carriage return, form feed, or vertical tab).
 * Returns zero if not.
 */
unsigned char isSpace(char ch);

/*******************************************************************************
 * unsigned char isUpper(char ch)
 *
 * Returns nonzero if ch is an uppercase letter character or zero if not.
 */
unsigned char isUpper(char ch);

/*******************************************************************************
 * unsigned char isXdigit(char ch)
 *
 * Returns nonzero if ch is a hexadecimal digit [0-9a-fA-F] character.
 * Returns zero if not.
 */
unsigned char isXdigit(char ch);

