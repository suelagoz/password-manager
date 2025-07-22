#include <stdio.h>
#include <string.h>
#include "encrypt.h"
#include "file_ops.h"

    void add_password(){
    char site [100];
    char password[100];
    char username[100];
    char encrypted_password[100];

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
     void view_passwords() {
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char site[50], username[50], encrypted_password[50];
    printf("\n--- Passwords ---\n");
   
    while (fscanf(fp, "%49s %49s %49s\n", site, username, encrypted_password) == 3) {
        char decrypted_password[50];
        strcpy(decrypted_password, encrypted_password);
        decrypt(decrypted_password); 
        printf("Site: %s, Username: %s, Password: %s\n", site, username, decrypted_password);
    }
    fclose(fp);
    printf("-------------------------\n");
         
    }void delete_password() {
    char site_to_delete[50];
    printf("Enter the site name that you want to delete:\n");
   
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    fgets(site_to_delete, sizeof(site_to_delete), stdin);
    site_to_delete[strcspn(site_to_delete, "\n")] = 0;

    FILE *fp_read = fopen("passwords.txt", "r");
    if (fp_read == NULL) {
        printf("Error creating temporary file.\n");
        return;
    }

    FILE *fp_write = fopen("temp_passwords.txt", "w"); 
    if (fp_write == NULL) {
        printf("Error opening the file.\n");
        fclose(fp_read);
        return;
    }

    char site[50], username[50], encrypted_password[50];
    int found = 0;
    while (fscanf(fp_read, "%49s %49s %49s\n", site, username, encrypted_password) == 3) {
        if (strcmp(site, site_to_delete) == 0) {
            found = 1; 
        } else {
            fprintf(fp_write, "%s %s %s\n", site, username, encrypted_password); 
        }
    }

    fclose(fp_read);
    fclose(fp_write);
     if (found) {
        remove("passwords.txt"); 
        rename("temp_passwords.txt", "passwords.txt"); 
        printf("Password deleted successfully.\n"); 
    } else {
        remove("temp_passwords.txt"); 
        printf("Password not found.\n"); 
    }
}
