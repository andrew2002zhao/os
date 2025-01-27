global kernel_stack
; 4kB
KERNEL_STACK_SIZE equ 4096

section .bss:
align 4
kernel_stack: ;represents a memory location
  resb KERNEL_STACK_SIZE  ; what is resb, i think its reserving the stack???
  mov esp, kernel_stack + KERNEL_STACK_SIZE ;start at the top of the stack and grow downwards