CC=i386-elf-gcc
AS=nasm
LD=i386-elf-ld

CCFLAGS=-Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c
ASFLAGS=-f elf

KERNEL_C_SRCS=$(wildcard src/*.c)
KERNEL_ASM_SRCS=$(wildcard src/*.asm)
KERNEL_OBJS=$(KERNEL_ASM_SRCS:.asm=.o) $(KERNEL_C_SRCS:.c=.o)

KERNEL=kernel.bin

all: kernel

clean:
	rm -f *.bin src/*.o

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ $<

%.o: %.asm
	$(AS) $(ASFLAGS) -o $@ $<

kernel: $(KERNEL_OBJS)
	$(LD) -T src/link.ld -o $(KERNEL) $^

run: kernel
	qemu-system-i386 -kernel $(KERNEL)
