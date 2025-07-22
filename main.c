#include <stdio.h>   
#include <stdlib.h> 
#include "encrypt.h"     
#include "file_ops.h"  

int main(){
    int choice;

    do {
        printf("\n PASSWORD MANAGER \n");
        printf("1 - Add new password. \n");
        printf("2 - View saved passwords.\n");
        printf("3 - Delete password.\n");
        printf("4 - Exit.\n");
        
        printf("Enter your choice:\n ");
        scanf("%d", &choice);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    
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
            printf("Exiting the program.\n");
            break;
        default:
            printf("Please try again.\n");
    }
    } while (choice != 4);

    return 0;

}
