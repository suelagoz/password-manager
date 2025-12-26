#ifndef ENCRYPT_H
#define ENCRYPT_H

#define KEY_LEN 32

void derive_key(const char *master, unsigned char *key);

int encrypt_string(const char *plaintext, unsigned char *ciphertext);
int decrypt_string(const unsigned char *ciphertext, char *plaintext);

#endif
