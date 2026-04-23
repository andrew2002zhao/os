# make file links both loader.s and stack.s together using the linkerscript link.ld
BUILD_DIR = build
LOG_DIR = logs

# Find all C source files in root, src/, and build object names in build/
C_SOURCES = $(wildcard *.c src/*.c)
C_OBJECTS = $(addprefix $(BUILD_DIR)/,$(C_SOURCES:.c=.o))

# Find all assembly source files in root and assembly/, build object names in build/
ASSEMBLY_SOURCES = $(wildcard *.s assembly/*.s)
ASSEMBLY_OBJECTS = $(addprefix $(BUILD_DIR)/,$(ASSEMBLY_SOURCES:.s=.o))

OBJECTS = $(C_OBJECTS) $(ASSEMBLY_OBJECTS)
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c -Iinclude
# searches include Iinclude
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)	
	ld $(LDFLAGS) $(OBJECTS) -o $(BUILD_DIR)/kernel.elf


run : os.iso
	bochs -f bochsrc.txt -q

os.iso: kernel.elf
	cp $(BUILD_DIR)/kernel.elf  iso/boot/kernel.elf
	genisoimage -R                    \
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
$(BUILD_DIR)/%.o : %.c 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ 

$(BUILD_DIR)/%.o : %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

clean :
	rm -rf $(BUILD_DIR) os.iso bochslog.txt com1.out test_runner


C_TESTS = $(wildcard test/*_test.c)

test: test/Unity/src/unity.c $(C_TESTS)
	gcc -Itest -Itest/Unity/src -Iinclude test/Unity/src/unity.c $(C_TESTS) $(C_SOURCES) -o test_runner
	./test_runner
