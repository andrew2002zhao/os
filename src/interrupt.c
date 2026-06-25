#include "interrupt.h"

InterruptTableEntry idt[256];
void idt_setup() {
  load_idt(idt);
  
}