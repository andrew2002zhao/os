#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/*
FBWriteData
Bit:     | 15 14 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0 |
Content: | ASCII                 | FG      | BG      |
*/ 
// bit alignment
typedef struct FBWriteData{
  int ascii : 8;
  int fg : 4;
  int bg : 4;
} FBWriteData;


/** outb:
 *  Sends the given data to the given I/O port. Defined in io.s
 *
 *  @param port The I/O port to send the data to
 *  @param data The data to send to the I/O port
 */
void outb(unsigned short port, unsigned char data);

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

#endif /* INCLUDE_IO_H */