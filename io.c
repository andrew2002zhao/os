#include "io.h"

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

/* Frame Buffer Colors */
#define FB_GREEN     2
#define FB_DARK_GREY 8

/* Frame Buffer Address */
#define FB_ADDRESS 0x000B8010

static int fb_position = 0;

void fb_write_cell(FBWriteData fbWriteData) {
  char * fb = (char *) FB_ADDRESS;
  fb[fb_position] = fbWriteData.ascii;
  //combine both fg and bg so then 
  fb[fb_position + 1] = (fbWriteData.fg & 0x0F) << 4 | (fbWriteData.bg & 0x0F); 
}


void fb_move_cursor(unsigned short pos) {
  outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
  outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
  outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
  outb(FB_DATA_PORT,    pos & 0x00FF);
}
