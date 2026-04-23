#ifndef INCLUDE_PRINT_H
#define INCLUDE_PRINT_H

#define CONSOLE 0
#define SERIAL 1 

typedef enum Device {
  Console,
  Serial
} Device;

/**
 * print:
 * Takes a string and parses it, replacing % with variables passed into the parameter
 * %s is a string variable
 * %d is an integer
 * %f is a float
 * 
 * @param string the input string
 * @param device the output device
 */


void print(char* string, Device device, ...);

#endif 