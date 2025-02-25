#define FB_GREEN     2
#define FB_DARK_GREY 8

#define FB_ADDRESS 0x000B8010

int fb_position = 0;

/*
FBWriteData
Bit:     | 15 14 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0 |
Content: | ASCII                 | FG      | BG      |
*/ 

typedef struct FBWriteData{
  int ascii : 8;
  int fg : 4;
  int bg : 4;
} FBWriteData;

void fb_write_cell(FBWriteData fbWriteData) {
  char * fb = (char *) FB_ADDRESS;
  fb[fb_position] = fbWriteData.ascii;
  //combine both fg and bg so then 
  fb[fb_position + 1] = (fbWriteData.fg & 0x0F) << 4 | (fbWriteData.bg & 0x0F); 
}



int sum_of_three(int arg1, int arg2, int arg3) {
  return arg1 + arg2 + arg3;
}