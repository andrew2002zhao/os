
#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H
/** 
 * strlen:
 * Takes a null terminated c-string and counts the number of characters.
 * NOTE MUST NULL TERMINATE STRINGS 
 * 
 * @param len The length of the input string
 * @return The length of the string
 *          0 if a string is empty 
 *         -1 if call fails
 */
int strlen(char* string);

#endif