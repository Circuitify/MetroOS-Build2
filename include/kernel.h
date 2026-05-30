#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>

// Multiboot structuur om het adres van het videoscherm te krijgen
struct multiboot_info {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    uint32_t num[4];
    uint32_t size;
    uint32_t addr; // Dit is het fysieke adres van het scherm!
} __attribute__((packed));

// Grafische functies
void DrawPixel(int x, int y, uint32_t color);
void DrawRectangle(int x, int y, int width, int height, uint32_t color);
void DrawWindow(int x, int y, int w, int h, const char* title);

// Apps
void KernelFileManager(void);
void KernelTextEditor(void);

#endif
