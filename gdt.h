#ifndef INCLUDE_GDT_H
#define INCLUDE_GDT_H

/*
GDT
Index	Offset	    Name	              Address range	          Type   DPL
0	    0x00	      null descriptor			
1	    0x08	      kernel code segment	0x00000000 - 0xFFFFFFFF	RX	   PL0
2	    0x10	      kernel data segment	0x00000000 - 0xFFFFFFFF	RW	   PL0

EACH GDT ENTRY IS A 64 bit struct with the following format

Bit:      | 63 62 61 60 59 58 57 56 | 55 | 54 | 53 | 52 | 51 50 49 48 | 47 | 46 45 | 44 | 43 42 41 40 | 39 38 37 36 35 34 33 32
Content:  | Base Address (24 - 31)  | G  | DB | L  | A  | Limit(16-19)| P  | DPL   | S  | Type        | Base Address (16 - 23)

Bit:      | 31 30 29 28 27 26 25 24   23   22   21   20   19 18 17 16 | 15   14 13   12   11 10 9  8    7  6  5  4  3  2  1  0 
Content   | Base Address (0 - 15)                                     | Segment Limit (0- 15)

NULL DESCRIPTOR
Data :    | 0  0  0  0  0  0  0  0  | 0  | 0  | 0  | 0  | 0  0  0  0  | 0 | 0  0   | 0  | 0  0  0  0  | 0  0  0  0  0  0  0  0 
Data:     | 0  0  0  0  0  0  0  0    0    0    0    0    0  0  0  0  | 0   0  0     0    0  0  0  0    0  0  0  0  0  0  0  0 

KERNEL CODE DESCRIPTOR
Data :    | 0  0  0  0  0  0  0  0  | 1  | 0  | 0  | 0  | 1  1  1  1  | 1 | 0  0   | 1  | 1  0  1  0  | 0  0  0  0  0  0  0  0 
Data:     | 0  0  0  0  0  0  0  0    0    0    0    0    0  0  0  0  | 1   1  1     1    1  1  1  1    1  1  1  1  1  1  1  1 

KERNEL DATA DESCRIPTOR
Data :    | 0  0  0  0  0  0  0  0  | 1  | 0  | 0  | 0  | 1  1  1  1  | 1 | 0  0   | 1  | 0  0  1  0  | 0  0  0  0  0  0  0  0 
Data:     | 0  0  0  0  0  0  0  0    0    0    0    0    0  0  0  0  | 1   1  1     1    1  1  1  1    1  1  1  1  1  1  1  1 


*/

typedef struct GDT {
  int segment_limit_0_15 : 16;
  int base_address_0_15 : 16;
  int base_address_16_23 : 8;
  int type : 4;
  int s : 1;
  int dpl : 2;
  int p : 1;
  int limit_16_19 : 4;
  int a : 1;
  int l : 1;
  int db : 1;
  int g : 1;
  int base_address_24_31 : 8;
} __attribute__((packed)) GDT;

/*
A GDT Descriptor points to the GDT and is loaded with lgdt [eax] where eax is the pointer to the GDTR struct

struct gdt {
    unsigned int address; // the address to the GDT
    unsigned short size;  // THE SIZE OF THE TABLE IN BYTES - 1 (23)
} __attribute__((packed));

*/


typedef struct GDTR {
  unsigned short size;
  unsigned int address;
} __attribute__((packed)) GDTR;

void gdt_setup();
/**
 * load_gdt
 * takes a pointer to a global descriptor struct
 * 
 * @param gdtr
 * The address to a global descriptor struct
 */
void load_gdt(GDTR * gdtr);
#endif