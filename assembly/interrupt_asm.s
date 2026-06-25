global load_idt

; load_idt - loads the interrupt descriptor table
; stack: [esp + 4] the address of the interrupt descriptor table

load_idt:
  mov eax, [esp + 4]
  lidt [eax]
  ret

%macro no_error_code_interrupt_handler %1
global interrupt_handler_%1
interrupt_handler_%1:
    push    dword 0                     ; push 0 as error code
    push    dword %1                    ; push the interrupt number
    jmp     common_interrupt_handler    ; jump to the common handler
%endmacro

%macro error_code_interrupt_handler %1
global interrupt_handler_%1
interrupt_handler_%1:
    push    dword %1                    ; push the interrupt number
    jmp     common_interrupt_handler    ; jump to the common handler
%endmacro

common_interrupt_handler:
  ;save cpu state registers
  push ebp
  push ecx
  push ebx
  push eax

  call interrupt_handler

  pop eax
  pop ebx
  pop ecx 
  pop ebp
  add esp, 8
  iret