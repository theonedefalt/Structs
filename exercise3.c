#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct client
{
    int code;
    char email[80];
    float hours;
    char hasPage;
} client;

client *registerClients()
{
    client *clientArray = malloc(500 * sizeof(client));

    printf("***********************************************\n");
    printf("*            REGISTER CLIENT INFORMATION       *\n");
    printf("***********************************************\n");

    for (int i = 0; i < 500; i++)
    {
        printf("Enter client code: ");
        scanf("%d", &clientArray[i].code);
        printf("Enter client email: ");
        scanf("%s", clientArray[i].email);
        printf("Enter client access hours: ");
        scanf("%f", &clientArray[i].hours);
        printf("Does the client have a webpage? (Y/N): ");
        scanf(" %c", &clientArray[i].hasPage);
    }

    return clientArray;
}

void calculatePayment(client clientArray[], float paymentAmount[])
{
    for (int i = 0; i < 500; i++)
    {
        float amount = 0.0;

        if (clientArray[i].hours <= 20)
        {
            amount += 35.0;
        }
        else
        {
            amount = 35.0 + (clientArray[i].hours - 20) * 2.5;
        }

        if (clientArray[i].hasPage == 'Y')
        {
            amount += 40.0;
        }

        paymentAmount[i] = amount;
    }
}

void displayPayments(client clientArray[], float paymentAmount[])
{
    printf("***********************************************\n");
    printf("*                PAYMENT AMOUNT                *\n");
    printf("***********************************************\n");

    for (int i = 0; i < 500; i++)
    {
        printf("Client Code: %d\n", clientArray[i].code);
        printf("Payment Amount: %.2f\n", paymentAmount[i]);
    }
}

int main(void)
{
    client *clientArray;
    float paymentAmount[500];

    clientArray = registerClients();

    calculatePayment(clientArray, paymentAmount);

    displayPayments(clientArray, paymentAmount);

    free(clientArray);

    return 0;
}
