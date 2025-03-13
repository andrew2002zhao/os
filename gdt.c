#include "gdt.h"


GDT gdt[3];

void gdt_setup() {
    
    //KERNEL CODE DESCRIPTOR
    gdt[1].g = 1;
    gdt[1].limit_16_19 = 0b1111;
    gdt[1].p = 1;
    gdt[1].s = 1;
    gdt[1].type = 0b1010;
    gdt[1].segment_limit_0_15 = 0b11111111;
    gdt[1].db = 1;
    //KERNEL DATA DESCRIPTOR
    gdt[2].g = 1;
    gdt[2].limit_16_19 = 0b1111;
    gdt[2].p = 1;
    gdt[2].s = 1;
    gdt[2].type = 0b0010;
    gdt[2].segment_limit_0_15 = 0b11111111;
    gdt[2].db = 1;

    GDTR gdtr;
    gdtr.address = (unsigned int) &gdt;
    gdtr.size = 8 * 3 - 1;
    load_gdt(&gdtr);
}