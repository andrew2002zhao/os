#include "io.h"
#include "serial.h"
#include "gdt.h"
/* Frame Buffer Colors */
#define FB_GREEN     2
#define FB_DARK_GREY 8

#define SERIAL_COM1_BASE                0x3F8      /* COM1 base port */

int main() {
  serial_setup(SERIAL_COM1_BASE);
  //setup the gdt
  gdt_setup();
  // serial_write(SERIAL_COM1_BASE, "HELLO WORLD!HELLO WORLD!HELLO WORLD!HELLO WORLD!HELLO WORLD!", 60);

  fb_write("HELLO WORLD!HELLO WORLD!HELLO WORLD!HELLO WORLD!HELLO WORLD!HELLO WORLD!", 72);

  return 0;
}