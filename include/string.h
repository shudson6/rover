/*******************************************************************************
 * string.h
 *
 * String functions needed for the project.
 */

/*******************************************************************************
 * int atoi(const char* str)
 *
 * Converts a string to an integer. Leading whitespace is ignored. As many
 * characters as form a valid integer are processed into an int. Any trailing
 * characters are ignored. If no conversion is possible, zero is returned. If
 * the represented value is larger than fits in an int, return value is 
 * undefined.
 */
int atoi(const char* str);


/*******************************************************************************
 * unsigned char isalnum(char ch)
 *
 * Returns nonzero if ch is an alphanumeric character or zero if not.
 */
unsigned char isalnum(char ch);

/*******************************************************************************
 * unsigned char isalpha(char ch)
 *
 * Returns nonzero if ch is an alphabet character or zero if not.
 */
unsigned char isalpha(char ch);

/*******************************************************************************
 * unsigned char isdigit(char ch)
 *
 * Returns nonzero if ch is a digit [0-9] character or zero if not.
 */
unsigned char isdigit(char ch);

/*******************************************************************************
 * unsigned char islower(char ch)
 *
 * Returns nonzero if ch is a lowercase letter character or zero if not.
 */
unsigned char islower(char ch);

/*******************************************************************************
 * unsigned char isspace(char ch)
 *
 * Returns nonzero if ch is a whitespace character (space, tab, newline, 
 * carriage return, form feed, or vertical tab).
 * Returns zero if not.
 */
unsigned char isspace(char ch);

/*******************************************************************************
 * unsigned char isupper(char ch)
 *
 * Returns nonzero if ch is an uppercase letter character or zero if not.
 */
unsigned char isupper(char ch);

/*******************************************************************************
 * unsigned char isxdigit(char ch)
 *
 * Returns nonzero if ch is a hexadecimal digit [0-9a-fA-F] character.
 * Returns zero if not.
 */
unsigned char isxdigit(char ch);

