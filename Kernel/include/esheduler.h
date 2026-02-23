#ifndef ESHEDULER_H
#define ESHEDULER_H

// "Mini-Cos" function
float l_cos(float x) {
    float res = 1.0f;
    float term = 1.0f;
    float x2 = x * x;
    for (int i = 1; i <= 3; i++) { 
        term *= -x2 / (float)((2 * i - 1) * (2 * i));
        res += term;
    }
    return res;
}

static unsigned long long system_ticks = 0;

// Esheduler: a basic round-robin scheduler
void esheduler_tick() {
    system_ticks++;
    
    // formula: 3 * cos(ticks * 100)
    float heartbeat = 3.0f * l_cos((float)system_ticks * 0.1f); 
    
}

#endif