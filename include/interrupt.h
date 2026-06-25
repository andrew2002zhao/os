#ifndef INCLUDE_INTERRUPT_H
#define INCLUDE_INTERRUPT_H

/*
Interrupt Table Entry
Bit:     | 63             48  | 47 | 46 45 | 44 | 43 | 42 41 40 | 39 38 37 | 36 35 34 33 32 |
Content: | offset high        | P  | DPL   | 0  | D  |  1  1  0 |  0  0  0 | reserved       |
Bit:     | 31              16 | 15              0 |
Content: | segment selector   | offset low        |


The offset is the address of code (preferrably an assembly code label)
*/


typedef struct InterruptTableEntry {
  int offset_high : 16;
  int handler_present : 1;
  int descriptor_privilge_level : 2;
  int _hardset_zero : 1;
  int size_of_gate : 1;
  int _hardset_one_one_zero_zero_zero_zero : 6;
  int reserved : 5;
  int segment_selector : 16;
  int offset_low : 16;
}__attribute__((packed)) InterruptTableEntry;

struct cpu_state {
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int ebp;
} __attribute__((packed));

struct stack_state {
    unsigned int error_code;
    unsigned int eip;
    unsigned int cs;
    unsigned int eflags;
} __attribute__((packed));

/**
 * interrupt_handler
 * a generic interrupt handler function used to handle interrupts in c from asm
 * 
 * @param cpu the state of the cpu registers before the interrupt
 * @param stack information about where the previous code pointer and segment before interrupt
 * @param interrupt the interrupt number
 */

void interrupt_handler(struct cpu_state cpu, unsigned int interrupt, struct stack_state stack);

//tell c that interrupt_handler_0 is defined in thce asm file already
extern void interrupt_handler_0(void);

/**
 * load_idt
 * load the idt from a memory address
 * 
 * @param interrupt_table the address of the first entry of the interrupt table
 */

void load_idt (InterruptTableEntry * interrupt_table);



/**
 * idt_setup
 * 
 * creates an interrupt table and calls load_idt
 */
void idt_setup();

#endif