#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente {
    char name[80];
    char address[80];
    int phone;
} cliente;

void registerClient(cliente *client1, cliente *client2) {
    printf("***********************************************\n");
    printf("*           REGISTER CLIENT INFORMATION        *\n");
    printf("***********************************************\n");

    printf("\nEnter the name of the first client: ");
    scanf("%s", client1->name);
    printf("Enter the address of the first client: ");
    scanf("%s", client1->address);
    printf("Enter the phone number of the first client: ");
    scanf("%d", &client1->phone);

    printf("\nEnter the name of the second client: ");
    scanf("%s", client2->name);
    printf("Enter the address of the second client: ");
    scanf("%s", client2->address);
    printf("Enter the phone number of the second client: ");
    scanf("%d", &client2->phone);
}

void displayClients(cliente *client1, cliente *client2) {
    printf("***********************************************\n");
    printf("*                 CLIENT INFORMATION           *\n");
    printf("***********************************************\n");

    printf("Name of the first client: %s | Name of the second client: %s\n", client1->name, client2->name);
    printf("Address of the first client: %s | Address of the second client: %s\n", client1->address, client2->address);
    printf("Phone number of the first client: %d | Phone number of the second client: %d\n", client1->phone, client2->phone);
}

int main(void) {
    cliente client1;
    cliente client2;

    registerClient(&client1, &client2);

    displayClients(&client1, &client2);

    return 0;
}
