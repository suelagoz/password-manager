#include <stdio.h>
#include <string.h>
#include "encrypt.h"
#include "file_ops.h"

void add_password(){
    char site [50];
    char password[50];
    char username[50];
    char encrypted_password[50];
}
    printf("Enter site name:\n");
    fgets(site, sizeof(site), stdin);
    site[strcspn(site, "\n")] = 0; 

    printf("Enter username:\n");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password:\n");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    
    strcpy(encrypted_password, password);
    encrypt(encrypted_password);

    
    FILE *fp = fopen("passwords.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(fp, "%s %s %s\n", site, username, encrypted_password);
    fclose(fp);

    printf("Password added!\n");
}
