#include "encrypt.h"

void encrypt(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = str[i] + 2;
        i++;
    }
}

void decrypt(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = str[i] - 2;  
        i++;
    }
}
