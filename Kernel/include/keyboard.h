// KEYBOARD 

// keyboard.h
#include "io.h"

char get_keypress() {
   // "Bit 1 of Port 0x64 means 'data is present'"
    while (!(inb(0x64) & 1)); 
    
    unsigned char scancode = inb(0x60);
    
    if (scancode == 0x1E) return 'a';
    if (scancode == 0x30) return 'b';
    if (scancode == 0x2E) return 'c';
    if (scancode == 0x20) return 'd';
    if (scancode == 0x12) return 'e';
    if (scancode == 0x21) return 'f';
    if (scancode == 0x22) return 'g';
    if (scancode == 0x23) return 'h';
    if (scancode == 0x17) return 'i';  
    if (scancode == 0x24) return 'j';
    if (scancode == 0x25) return 'k';
    if (scancode == 0x26) return 'l';
    if (scancode == 0x32) return 'm';
    if (scancode == 0x31) return 'n';
    if (scancode == 0x18) return 'o';
    if (scancode == 0x19) return 'p';
    if (scancode == 0x10) return 'q';
    if (scancode == 0x13) return 'r';
    if (scancode == 0x1F) return 's';
    if (scancode == 0x14) return 't';
    if (scancode == 0x16) return 'u';
    if (scancode == 0x2F) return 'v';
    if (scancode == 0x11) return 'w';
    if (scancode == 0x2D) return 'x';
    if (scancode == 0x15) return 'y';
    if (scancode == 0x2C) return 'z';
    if (scancode == 0x39) return ' ';
    if (scancode == 0x02) return '1'; 
    if (scancode == 0x03) return '2';
    if (scancode == 0x04) return '3';
    if (scancode == 0x05) return '4';
    if (scancode == 0x06) return '5';
    if (scancode == 0x07) return '6';
    if (scancode == 0x08) return '7';
    if (scancode == 0x09) return '8';
    if (scancode == 0x0A) return '9';
    if (scancode == 0x0B) return '0';
    if (scancode == 0x4A) return '-';
    if (scancode == 0x4E) return '+';
    if (scancode == 0x56) return '<';
    if (scancode == 0x48) return 'U'; // Up
    if (scancode == 0x50) return 'D'; // Down
    if (scancode == 0x4B) return 'L'; // Left
    if (scancode == 0x4D) return 'R'; // Right
    if (scancode == 0x1C) return '\n'; // Enter tuşu
    
    return 0;
}