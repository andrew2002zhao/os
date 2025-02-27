#include "io.h"

/* Frame Buffer Colors */
#define FB_GREEN     2
#define FB_DARK_GREY 8

int main() {
  FBWriteData fbWriteData;
  fbWriteData.ascii = 'a';
  fbWriteData.bg = FB_DARK_GREY;
  fbWriteData.fg = FB_GREEN;
  fb_write_cell(fbWriteData);
  return 0;
}