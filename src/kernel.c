#include "kernel.h"

void kernel_main(struct multiboot_info* mbi) {
    // 1. Start het grafische scherm
    InitScreen(mbi);

    // 2. Teken het Bureaublad (Klassiek Donkerblauw: 0x000088)
    DrawRectangle(0, 0, 800, 600, 0x000088);

    // 3. Teken de Taakbalk onderaan (Grijs: 0x888888)
    DrawRectangle(0, 560, 800, 40, 0x888888);
    
    // Teken de START-knop (Lichtgrijs: 0xCCCCCC)
    DrawRectangle(5, 565, 80, 30, 0xCCCCCC);

    // 4. Start en teken je C-Applicaties op het scherm
    KernelFileManager();
    KernelTextEditor();

    // De kernel mag nooit stoppen, dus we zetten hem in een oneindige loop
    while(1) {
        __asm__("hlt");
    }
}
