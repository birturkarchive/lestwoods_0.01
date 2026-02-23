#pragma once

void gimme_a_sec() {
  //  "Using volatile to prevent the compiler from optimizing out this empty loop."
    for (volatile unsigned int i = 0; i < 100000000; i++) {
        __asm__("nop");
    }
}
