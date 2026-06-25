global load_idt

; load_idt - loads the interrupt descriptor table
; stack: [esp + 4] the address of the interrupt descriptor table

load_idt:
  mov eax, [esp + 4]
  lidt eax
  ret