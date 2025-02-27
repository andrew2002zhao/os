global outb

; outb - send a byte to an I/O port
; stack: [esp + 8] the data byte
;        [esp + 4] the I/O port
;        [esp    ] return address
; c syntax - outb(int i/o, unsigned char data)
outb:
    mov al, [esp + 8] ;data byte
    mov dx, [esp + 4] ;i/o port
    out dx, al
    ret