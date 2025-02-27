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

static int fb_position = 20;

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
//TODO ADD TEXT WRAP AROUND
void fb_write(char * buffer, int len) {
  FBWriteData fbWriteData;
  fbWriteData.bg = FB_DARK_GREY;
  fbWriteData.fg = FB_GREEN;
  for(int i = 0; i < len; i++) {
    fbWriteData.ascii = buffer[i];
    fb_write_cell(fbWriteData);
    fb_move_cursor(fb_position);
    fb_position += 2;
  }
}
//TODO CREATE A print funciton with pattern matching
//TODO CREATE A printf function which adds a new space