#ifndef PRINTM_H
#define PRINTM_H

#include "esheduler.h"
static int cursor_pos = 0;

void check_scroll() {
    volatile unsigned short *video_memory = (unsigned short *)0xB8000;
    if (cursor_pos >= 80 * 25) {
        int N = 1; // Scroll by 1 line for now, can be increased if needed

        // 1. Move rows up by N lines
        for (int i = 0; i < 80 * (25 - N); i++) {
            video_memory[i] = video_memory[i + (80 * N)];
        }

        // 2. Clear the N lines newly opened at the bottom (fill with spaces)
        for (int i = 80 * (25 - N); i < 80 * 25; i++) {
            video_memory[i] = (unsigned short)' ' | (0x0F << 8);
        }

        // 3. Move the cursor up by N lines (to the start of the newly opened empty line)
        cursor_pos -= (80 * N);   
    }    
}

void printm(const char *str) {
    volatile unsigned short *video_memory = (unsigned short *)0xB8000;
    unsigned char renk = 0x0F; // Default color is white

    for (int i = 0; str[i] != '\0'; i++) {
        check_scroll();
        // Newline control
        if (str[i] == '\n') {
            cursor_pos += (80 - (cursor_pos % 80));
        } 
        else {
            // Write character and color to memory
            video_memory[cursor_pos++] = (unsigned short)str[i] | (renk << 8);
        }
    }
}

// Added a screen clear function for future use
void cls() {
    volatile unsigned short *video_memory = (unsigned short *)0xB8000;
    for (int i = 0; i < 80 * 25; i++) {
        video_memory[i] = (unsigned short)' ' | (0x0F << 8);
    }
    cursor_pos = 0;
}

#endif