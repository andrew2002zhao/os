
#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H
/** 
 * kstrlen:
 * Takes a null terminated c-string and counts the number of characters.
 * NOTE MUST NULL TERMINATE STRINGS 
 * 
 * @param string The input string
 * @return The length of the string
 *          0 if a string is empty 
 *         -1 if call fails
 */
int kstrlen(char* string);

/**
 * katoi:
 * Takes an integer string and returns a number.
 * Skips leading whitespace.
 * Reads a sign followed by base-10 digits
 * katoi returns at the first non-numeric character. 
 * 
 * Assumption: if no sign is specified, default to a positive integer
 * 
 * @param string The input string
 * @return The parsed integer
 * 
 */
int katoi(char* string);


/**
 * kitoa:
 * Takes an integer and returns the c-string representation.
 * 
 * @param num The input integer
 * @return The null-terminated c-string.
 *
 */
char* kitoa(int number);

/**
 * kstrcat:
 * Concatenates two strings and returns a new string pointer.
 * 
 * @param destination The destination string where the source string is copied to starting at the first null terminated character
 * @param source The source string to be copied over
 * @param maxlen The maximum length to carry over, i.e. the size of the destination buffer
 * 
 * Assumption: the destination buffer is large enough to hold both the source and destination strings
 * 
 * 
 * @return The concatenated null-terminated c-string.
 */

char* kstrlcat(char* destination, char* source, int maxlen);


#endif