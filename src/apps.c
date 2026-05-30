#include "kernel.h"

void KernelFileManager(void) {
    // Teken het venster voor File Manager op X: 50, Y: 50
    DrawWindow(50, 50, 350, 250, "File Manager");
    
    // Teken gesimuleerde bestanden (Mappen/bestanden als blokjes)
    DrawRectangle(70, 100, 15, 15, 0xFF0000); // Rood map-icoontje
    DrawRectangle(70, 130, 15, 15, 0xFF0000);
}

void KernelTextEditor(void) {
    // Teken het venster voor de Text Editor op X: 430, Y: 80
    DrawWindow(430, 80, 320, 300, "Text Editor");
    
    // Teken het witte type-vlak binnen de editor
    DrawRectangle(440, 120, 300, 240, 0xEEEEEE);
}
