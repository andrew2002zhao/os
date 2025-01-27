# make file links both loader.s and stack.s together using the linkerscript link.ld

all:
	nasm -f elf32 loader.s 
	nasm -f elf32 stack.s 
	ld -T link.ld -melf_i386 loader.o stack.o -o kernel.elf

	mv kernel.elf ./iso/boot/kernel.elf

	genisoimage -R                            \
						-b boot/grub/stage2_eltorito    \
						-no-emul-boot                   \
						-boot-load-size 4               \
						-A os                           \
						-input-charset utf8             \
						-quiet                          \
						-boot-info-table                \
						-o os.iso                       \
						iso

	rm -rf loader.o
	rm -rf stack.o