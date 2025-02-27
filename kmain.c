#include "io.h"

/* Frame Buffer Colors */
#define FB_GREEN     2
#define FB_DARK_GREY 8

int main() {
  
  fb_write("HELLO WORLD!", 12);

  return 0;
}