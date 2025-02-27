#include "io.h"
#include "serial.h"
/* Frame Buffer Colors */
#define FB_GREEN     2
#define FB_DARK_GREY 8

#define SERIAL_COM1_BASE                0x3F8      /* COM1 base port */

int main() {
  serial_setup(SERIAL_COM1_BASE);
  serial_write(SERIAL_COM1_BASE, "HELLO WORLD!", 12);
  // fb_write("HELLO WORLD!", 12);

  return 0;
}