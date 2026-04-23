#define CONSOLE 0
#define SERIAL 1 


typedef enum Device {
  Console,
  Serial
} Device;

/**
 * @param string the input string
 * @param device the output device
 */


void print(char* string, Device device, ...);