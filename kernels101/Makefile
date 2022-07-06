CC=i386-elf-gcc
AS=i386-elf-as
LD=i386-elf-gcc

CCFLAGS=-c -ffreestanding -O2 -Wall -Wextra 
ASFLAGS=
LDFLAGS=-ffreestanding -O2 -nostdlib

KERNEL_C_SRC=$(wildcard src/*.c)
KERNEL_S_SRC=$(wildcard src/*.s)
KERNEL_OBJ=$(KERNEL_S_SRC:.s=.o) $(KERNEL_C_SRC:.c=.o)

KERNEL=kernel.bin

all: kernel

clean:
	rm -f *.bin src/*.o

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ $<

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

kernel: $(KERNEL_OBJ)
	$(LD) $(LDFLAGS) -T src/link.ld -o $(KERNEL) $^

run: kernel
	qemu-system-i386 -kernel $(KERNEL)
