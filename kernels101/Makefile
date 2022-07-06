CC=gcc
AS=nasm
LD=ld

CCFLAGS=-c -m32
ASFLAGS=-f elf32
LDFLAGS=-m elf_i386

KERNEL_C_SRC=$(wildcard src/*.c)
KERNEL_ASM_SRC=$(wildcard src/*.asm)
KERNEL_OBJ=$(KERNEL_ASM_SRC:.asm=.o) $(KERNEL_C_SRC:.c=.o)

KERNEL=kernel.bin

all: kernel

clean:
	rm -f *.bin src/*.o

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ $<

%.o: %.asm
	$(AS) $(ASFLAGS) -o $@ $<

kernel: $(KERNEL_OBJ)
	$(LD) $(LDFLAGS) -T src/link.ld -o $(KERNEL) $^

run: kernel
	qemu-system-i386 -kernel $(KERNEL)
