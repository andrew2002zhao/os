
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
 * 
 */

#endif