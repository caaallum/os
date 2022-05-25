CC=i686-elf-gcc
AS=i686-elf-as
LD=i686-elf-gcc

CCFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS=-ffreestanding -O2 -nostdlib -lgcc

KERNEL_C_SRC=$(wildcard src/*.c)
KERNEL_S_SRC=$(wildcard src/*.s)
KERNEL_OBJ=$(KERNEL_C_SRC:.c=.o) $(KERNEL_S_SRC:.s=.o)

KERNEL=bare_bones.bin
ISO=bare_bones.iso

all: dirs kernel

clean:
	rm -f src/*.o
	rm -rf bin isodir
	rm -f *.iso

%.o: %.c
	$(CC) -o $@ -c $< $(CCFLAGS)

%.o: %.s
	$(AS) -o $@ -c $<

dirs:
	mkdir -p bin

kernel: $(KERNEL_OBJ)
	$(LD) $^ -T src/link.ld -o ./bin/$(KERNEL) $(LDFLAGS)

run-bin: kernel
	qemu-system-i386 -kernel ./bin/$(KERNEL)

iso: kernel
	mkdir -p isodir/boot/grub
	cp bin/$(KERNEL) isodir/boot/$(KERNEL)
	cp src/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) isodir

run-iso: iso
	qemu-system-i386 -cdrom $(ISO)
