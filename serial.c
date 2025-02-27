#include "serial.h"

/* The I/O ports */

/* All the I/O ports are calculated relative to the data port. This is because
 * all serial ports (COM1, COM2, COM3, COM4) have their ports in the same
 * order, but they start at different values.
 */

#define SERIAL_COM1_BASE                0x3F8      /* COM1 base port */

#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

/* The I/O port commands */

/* SERIAL_LINE_ENABLE_DLAB:
* Tells the serial port to expect first the highest 8 bits on the data port,
* then the lowest 8 bits will follow
*/
 #define SERIAL_LINE_ENABLE_DLAB         0x80

void serial_configure_baud_rate(unsigned short com, unsigned short divisor) {
    outb(SERIAL_LINE_COMMAND_PORT(com),
          SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com),
          (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com),
          divisor & 0x00FF);
}

void serial_configure_line(unsigned short com) {
    // configuring serial line
    /* Bit:     | 7 | 6 | 5 4 3 | 2 | 1 0 |
     * Content: | d | b | prty  | s | dl  |
     * Value:   | 0 | 0 | 0 0 0 | 0 | 1 1 | = 0x03
     */
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);

    // configuring the fifo queue
    /*
    *  Bit:     | 7 6 | 5  | 4 | 3   | 2   | 1   | 0 |
    *  Content: | lvl | bs | r | dma | clt | clr | e |
    *  Data:    | 1 1 | 0  | 0 | 0   | 1   | 1   | 1 |
    */
    outb(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);

    // configuring the modem
    /*
    *  Bit:     | 7 | 6 | 5  | 4  | 3   | 2   | 1   | 0   |
    *  Content: | r | r | af | lb | ao2 | ao1 | rts | dtr |
    *  Data:    | 0 | 0 | 0  | 0  | 0   | 0   | 1   | 1   |
    */
    outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);
}
int serial_is_transmit_fifo_empty(unsigned int com) {
  /* 0x20 = 0010 0000 */
  return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void serial_setup(unsigned short com){
  serial_configure_baud_rate(com, 1);
  serial_configure_line(com);
}

void serial_write(unsigned short com, char * buffer, int len){
  for(int i = 0; i < len; i++) {
    //check if buffer is available
    serial_is_transmit_fifo_empty(com);
    //send out a byte 
    outb(SERIAL_DATA_PORT(com), buffer[i]);
  }
}