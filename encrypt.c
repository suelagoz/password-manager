#include "encrypt.h"
#include <string.h>
#include <stdint.h>

static uint32_t state = 0;

void init_crypto(const char *master) {
    // master password'tan pseudo key üret
    for (int i = 0; master[i]; i++)
        state = state * 131 + master[i];
}

static uint8_t keystream() {
    // xorshift PRNG
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return (uint8_t)(state & 0xFF);
}

void encrypt_string(char *data) {
    for (int i = 0; data[i]; i++)
        data[i] ^= keystream();
}

void decrypt_string(char *data) {
    encrypt_string(data); // XOR symmetric
}
