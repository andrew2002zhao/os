#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/*
FBWriteData
Bit:     | 15 14 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0 |
Content: | ASCII                 | FG      | BG      |
*/ 
// bit alignment

/*
fb[0] = ascii
fb[1] = color

VGA frame buffer is big endian memory layout
*/
typedef struct FBWriteData{
  int bg : 4;
  int fg : 4;
  int ascii : 8;
} __attribute__((packed))FBWriteData;



_Static_assert(sizeof(FBWriteData) == 2, "FBWriteData should be 2 bytes!");

/** outb:
 *  Sends the given data to the given I/O port. Defined in io.s
 *
 *  @param port The I/O port to send the data to
 *  @param data The data to send to the I/O port
 */
void outb(unsigned short port, unsigned char data);

/** inb:
 *  Reads a byte from a given port and returns it back
 * 
 *  @param port The address of the I/O port
 *  @return     The read byte
 */

unsigned char inb(unsigned short port);

/** fb_write_cell
 * puts an ascii value inside the framebuffer with a foreground color and background color. Writes to the current frame buffer position
 * 
 * @param fbWriteData
 * a struct containing both the character ascii encoded as well as a foreground and background color
 */

void fb_write_cell(FBWriteData fbWriteData);

/** fb_move_cursor:
 *  Moves the cursor of the framebuffer to the given position
 *
 *  @param pos The new position of the cursor
 */

void fb_move_cursor(unsigned short pos);

/** 
 * fb_write
 * Write to the screen. Text wraps around when reading.
 *
 * @param buffer The input buffer
 */
void fb_write(char * buffer);

#endif /* INCLUDE_IO_H */