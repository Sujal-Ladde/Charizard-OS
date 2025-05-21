# Tools
CC      := gcc
CFLAGS  := -m32 -std=gnu99 -ffreestanding -O2 -Wall
LDFLAGS := -m32 -T linker.ld -ffreestanding -nostdlib

# Source files
SRC_C   := kernel/arch.c kernel/main.c kernel/scheduler.c kernel/vga.c
ASM_SRC := kernel/entry.S kernel/gdt.S
OBJS    := $(SRC_C:.c=.o) $(ASM_SRC:.S=.o)

# Default target
all: iso/charizard_v1.iso

# Compile C sources
%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

# Assemble assembly sources
%.o: %.S
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

# Link kernel binary
kernel.bin: $(OBJS) linker.ld
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

# Create bootable ISO
iso/charizard_v1.iso: kernel.bin
	mkdir -p iso/boot/grub
	cp kernel.bin iso/boot/
	echo "set timeout=0" > iso/boot/grub/grub.cfg
	echo "menuentry \"Charizard OS v1.0\" {" >> iso/boot/grub/grub.cfg
	echo "  multiboot /boot/kernel.bin" >> iso/boot/grub/grub.cfg
	echo "  boot" >> iso/boot/grub/grub.cfg
	echo "}" >> iso/boot/grub/grub.cfg
	grub-mkrescue -o $@ iso

# Cleanup build artifacts
clean:
	rm -f $(OBJS) kernel.bin
	rm -rf iso