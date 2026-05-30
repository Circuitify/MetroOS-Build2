#include "kernel.h"

uint32_t* framebuffer;

void InitScreen(struct multiboot_info* mbi) {
    // Haal het schermadres op uit de bootloader
    framebuffer = (uint32_t*)((uint32_t)mbi->addr);
}

// Kleur een specifieke pixel op het scherm (X, Y)
void DrawPixel(int x, int y, uint32_t color) {
    if (x >= 0 && x < 800 && y >= 0 && y < 600) {
        framebuffer[y * 800 + x] = color;
    }
}

// Teken een gevulde rechthoek
void DrawRectangle(int x, int y, int width, int height, uint32_t color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            DrawPixel(x + j, y + i, color);
        }
    }
}

// Teken een OS Venster (Frame + Titelbalk)
void DrawWindow(int x, int y, int w, int h, const char* title) {
    DrawRectangle(x, y, w, h, 0xFFFFFFFF);         // Wit venster (Background)
    DrawRectangle(x, y, w, 30, 0 Lord_0x0000FF);  // Blauwe titelbalk (0x0000FF = Blauw)
}
