ENTRY(loader) /* entry point for the bootloader */

SECTIONS {
  /* the . tells where the current memory segment is */
  . = 0x00100000;
  /* 4KB bounadries */
  /* any kind of instructions are put into this memory section */
  .text ALIGN (0x1000) : {
    /* * is a wild card  */
    *(.text)
  }
  .rodata ALIGN (0x1000) : {
    /* contains both constants and string literals */
    *(.rodata*)
  }
  .data ALIGN (0x1000) : {
    /* initialized global and static variables */
    *(.data)
  }
  .bss ALIGN (0x1000) : {
    /* uninitialized global and static variables */
    /* doesnt take up space for initial in the elf binary file and just 0 initiaizlies */
    /* we use bss for stack memory since stack memory is always written to before reading and thus is ok with being uninitialized */
    *(COMMON)
    *(.bss)
  }
}