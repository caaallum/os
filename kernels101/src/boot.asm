bits 32                         ; nasm directive - 32 bit
section .text
    ; Multiboot spec
    align 4
    dd 0x1BADB002               ; Magic
    dd 0x00                     ; Flags
    dd - (0x1BADB002 + 0x00)    ; Checksum

global start
extern kmain                    ; kmain is defined in kernel.c

start:
    cli                         ; Block interrupts
    mov esp, stack_space        ; Set stack pointer
    call kmain
    hlt                         ; Halt the CPU

section .bss
resb 8192                       ; 8KB for stack
stack_space:
