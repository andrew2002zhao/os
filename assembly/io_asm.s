global outb
global inb

; outb - send a byte to an I/O port
; stack: [esp + 8] the data byte
;        [esp + 4] the I/O port
;        [esp    ] return address
; c syntax - outb(int i/o, unsigned char data)
; parameters are pushed onto the stack from right to left
; the left most paramter is top most on the stack
outb:
    mov al, [esp + 8] ;data byte
    mov dx, [esp + 4] ;i/o port
    out dx, al
    ret

; inb - returns a byte from the given I/O port
; stack: [esp + 4] The address of the I/O port
;        [esp    ] The return address

inb: 
    mov dx, [esp + 4]
    in al, dx
    ret