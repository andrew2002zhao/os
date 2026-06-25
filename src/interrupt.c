#include "interrupt.h"

InterruptTableEntry idt[256];
void idt_setup() {
  idt[0].offset_high = (unsigned int)&interrupt_handler_0 & 0xFFFF;
  idt[0].offset_low = ((unsigned int)&interrupt_handler_0 >> 16);
  idt[0]._hardcode_zero = 0;
  idt[0]._hardcode_one_one_zero_zero_zero_zero = 0b110000;

  
  load_idt(idt);
  
}
void interrupt_handler(struct cpu_state cpu, unsigned int interrupt, struct stack_state stack) {
  (void) cpu;
  (void) interrupt;
  (void) stack;
  return;
}
