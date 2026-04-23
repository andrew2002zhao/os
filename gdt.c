#include "gdt.h"
GDT gdt[3];




void gdt_setup() {
    //NULL DESCRIPTOR
    gdt[0].segment_limit_0_15 = 0;
    gdt[0].base_address_0_15 = 0;
    gdt[0].base_address_16_23 = 0;
    gdt[0].a = 0;
    gdt[0].rw = 0;
    gdt[0].dc = 0;
    gdt[0].e = 0;
    gdt[0].s = 0;
    gdt[0].dpl = 0;
    gdt[0].p = 0;
    gdt[0].limit_16_19 = 0;
    gdt[0].reserved = 0;
    gdt[0].l = 0;
    gdt[0].db = 0;
    gdt[0].g = 0;
    gdt[0].base_address_24_31 = 0;

    //KERNEL CODE DESCRIPTOR
    gdt[1].segment_limit_0_15 = 0xFFFF;
    gdt[1].base_address_0_15 = 0;
    gdt[1].base_address_16_23 = 0;
    gdt[1].a = 0;
    gdt[1].rw = 1;         // Readable
    gdt[1].dc = 0;         // Not conforming
    gdt[1].e = 1;          // Executable
    gdt[1].s = 1;          // Code/Data segment (not system)
    gdt[1].dpl = 0;        // Kernel privilege (DPL=0)
    gdt[1].p = 1;          // Present
    gdt[1].limit_16_19 = 0xF;
    gdt[1].reserved = 0;
    gdt[1].l = 0;          // Not long mode (32-bit)
    gdt[1].db = 1;         // 32-bit default
    gdt[1].g = 1;          // 4KB granularity
    gdt[1].base_address_24_31 = 0;

    //KERNEL DATA DESCRIPTOR
    gdt[2].segment_limit_0_15 = 0xFFFF;
    gdt[2].base_address_0_15 = 0;
    gdt[2].base_address_16_23 = 0;
    gdt[2].a = 0;
    gdt[2].rw = 1;         // Writable
    gdt[2].dc = 0;         // Expand up
    gdt[2].e = 0;          // Not executable (data)
    gdt[2].s = 1;          // Code/Data segment (not system)
    gdt[2].dpl = 0;        // Kernel privilege (DPL=0)
    gdt[2].p = 1;          // Present
    gdt[2].limit_16_19 = 0xF;
    gdt[2].reserved = 0;
    gdt[2].l = 0;          // Not long mode (32-bit)
    gdt[2].db = 1;         // 32-bit default
    gdt[2].g = 1;          // 4KB granularity
    gdt[2].base_address_24_31 = 0;

    GDTR gdtr;
    gdtr.address = (unsigned int) &gdt;
    gdtr.size = 8 * 3 - 1;
    load_gdt(&gdtr);
}