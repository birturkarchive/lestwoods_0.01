#ifndef IO_H
#define IO_H

static inline unsigned char inb(unsigned short port) {
    unsigned char val;
    __asm__ __volatile__ ("inb %1, %0" : "=a"(val) : "Nd"(port));
    return val;
}

#endif