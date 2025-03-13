global load_gdt

section .text
load_gdt:
  mov eax, [esp + 4]
  lgdt [eax]

  

  jmp 0x08:flush_cs
  

flush_cs:
        ; now we've changed cs to 0x08
  mov ax, 0x10
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  mov ss, ax 
  ret