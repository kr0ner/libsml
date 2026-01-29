#pragma once
#include <stdint.h>
#include <esp_random.h> // Native ESP32 random number generator

typedef uint8_t uuid_t[16];

// Mimic the Linux uuid_generate function using ESP32 hardware RNG
static inline void uuid_generate(uuid_t out) {
    esp_fill_random(out, 16);
    
    // Set version to 4 (random UUID) per RFC 4122
    out[6] = (out[6] & 0x0F) | 0x40;
    out[8] = (out[8] & 0x3F) | 0x80;
}
