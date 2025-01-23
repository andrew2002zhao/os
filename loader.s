global loader ;symbol is visible to the linker

MAGIC_NUMBER  equ 0x1BADB002
FLAGS         equ 0x0
CHECKSUM      equ -MAGIC_NUMBER

section .text:
align 4
  dd MAGIC_NUMBER
  dd FLAGS
  dd CHECKSUM

loader:
  mov eax, 0xCAFEBABE ;moves 0xCAFEBABE into the eax register
.loop:
  jmp .loop ;infinite loop where it keeps jumping back up to the loop label