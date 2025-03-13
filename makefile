# make file links both loader.s and stack.s together using the linkerscript link.ld
ASSEMBLY_OBJECTS = loader.o io_asm.o gdt_asm.o
C_OBJECTS = kmain.o io.o serial.o gdt.o
OBJECTS = $(C_OBJECTS) $(ASSEMBLY_OBJECTS)
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)	
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf


run : os.iso
	bochs -f bochsrc.txt -q

os.iso: kernel.elf
	cp kernel.elf  iso/boot/kernel.elf
	genisoimage -R                              \
							-b boot/grub/stage2_eltorito    \
							-no-emul-boot                   \
							-boot-load-size 4               \
							-A os                           \
							-input-charset utf8             \
							-quiet                          \
							-boot-info-table                \
							-o os.iso                       \
							iso

	

# $@ is an automatic variable for the target name
# $< outputs the prerequisite
%.o : %.c 
	$(CC) $(CFLAGS) $< -o $@ 

%.o : %.s
	$(AS) $(ASFLAGS) $< -o $@

clean :
	rm -rf *.o kernel.elf os.iso bochslog.txt com1.out