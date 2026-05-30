; Multiboot header voor Grafische Modus
MBALIGN     equ  1 << 0
MEMINFO     equ  1 << 1
VIDEO_MODE  equ  1 << 2
FLAGS       equ  MBALIGN | MEMINFO | VIDEO_MODE
MAGIC       equ  0x1BADB002
CHECKSUM    equ  -(MAGIC + FLAGS)

section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM
    ; VESA Grafische instellingen
    dd 0, 0, 0          ; Mode type (0 = lineair), breedte, hoogte (worden genegeerd)
    dd 0                ; 0 = Grafische modus
    dd 800, 600, 32     ; Wij willen 800x600 pixels, 32-bit kleur depth

section .bss
align 16
stack_bottom:
    resb 16384          ; 16 KiB Stack
stack_top:

section .text
global _start
_start:
    mov esp, stack_top
    push ebx            ; EBX bevat een pointer naar de Multiboot informatie (met het schermadres!)
    extern kernel_main
    call kernel_main

.hang:
    hlt
    jmp .hang
