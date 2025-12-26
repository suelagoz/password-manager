#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_LEN 32
#define SALT_FILE "vault.salt"
#define MASTER_HASH_FILE "vault.master"

void hash_master(const char *pass, unsigned char *out) {
    PKCS5_PBKDF2_HMAC(pass, strlen(pass),
        (unsigned char*)"static_salt", 11,
        100000, EVP_sha256(), KEY_LEN, out);
}

int verify_master() {
    unsigned char stored[KEY_LEN], entered[KEY_LEN];
    char input[100];

    FILE *fp = fopen(MASTER_HASH_FILE, "rb");
    if (!fp) {
        printf("Create master password:\n");
        fgets(input, 100, stdin);
        input[strcspn(input,"\n")] = 0;
        hash_master(input, stored);
        fp = fopen(MASTER_HASH_FILE, "wb");
        fwrite(stored, 1, KEY_LEN, fp);
        fclose(fp);
        return 1;
    }

    fread(stored, 1, KEY_LEN, fp);
    fclose(fp);

    printf("Enter master password:\n");
    fgets(input, 100, stdin);
    input[strcspn(input,"\n")] = 0;
    hash_master(input, entered);

    return memcmp(stored, entered, KEY_LEN) == 0;
}

