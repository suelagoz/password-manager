#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"
#include "file_ops.h"


int verify_master(char *out_master);

int main() {
    char master[100];

 
    if (!verify_master(master)) {
        printf("Vault locked.\n");
        return 0;
    }

    init_crypto(master);

    int choice;

    do {
        printf("\n= PASSWORD VAULT =\n");
        printf("1 - Add new password\n");
        printf("2 - View saved passwords\n");
        printf("3 - Delete password\n");
        printf("4 - Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            view_passwords();
            break;
        case 3:
            delete_password();
            break;
        case 4:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (choice != 4);

    return 0;
}


