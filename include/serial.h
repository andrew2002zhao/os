#ifndef INCLUDE_SERIAL_H
#define INCLUDE_SERIAL_H
#include "io.h" /* io.h is implement in the section "Moving the cursor" */



/** serial_configure_baud_rate:
 *  Sets the speed of the data being sent. The default speed of a serial
 *  port is 115200 bits/s. The argument is a divisor of that number, hence
 *  the resulting speed becomes (115200 / divisor) bits/s.
 *
 *  @param com      The COM port to configure
 *  @param divisor  The divisor
 */

void serial_configure_baud_rate(unsigned short com, unsigned short divisor);


/** serial_configure_line:
 *  Configures the line of the given serial port. The port is set to have a
 *  data length of 8 bits, no parity bits, one stop bit and break control
 *  disabled.
 *
 *  @param com  The serial port to configure
 */
void serial_configure_line(unsigned short com);

/** serial_is_transmit_fifo_empty:
 *  Checks whether the transmit FIFO queue is empty or not for the given COM
 *  port.
 *
 *  @param  com The COM port
 *  @return 0 if the transmit FIFO queue is not empty
 *          1 if the transmit FIFO queue is empty
 */
int serial_is_transmit_fifo_empty(unsigned int com);

/**
 * serial_setup:
 * sets up the serial port, only needs to be called once
 */
void serial_setup(unsigned short com);

/** 
 * serial_write:
 * writes a text string to the serial port 
 * @param buffer the buffer of data
 * @param len    the length of the input buffer
 */
void serial_write(unsigned short com, char * buffer, int len);
 

#endif