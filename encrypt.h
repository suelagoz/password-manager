#ifndef ENCRYPT_H
#define ENCRYPT_H

void init_crypto(const char *master);

void encrypt_string(char *data);
void decrypt_string(char *data);

#endif
