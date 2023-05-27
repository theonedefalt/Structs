#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record
{
    char name[80];
    float phone;
    float price;
} record;

record *registration()
{
    record *registrationArray = malloc(15 * sizeof(record));

    printf("***********************************************\n");
    printf("*            ENTER THE INFORMATION            *\n");
    printf("***********************************************\n");

    for (int i = 0; i < 15; i++)
    {
        printf("\nEnter the store name: ");
        scanf("%s", registrationArray[i].name);
        printf("Enter the store phone: ");
        scanf("%f", &registrationArray[i].phone);
        printf("Enter the price of an appliance: ");
        scanf("%f", &registrationArray[i].price);
    }

    return registrationArray;
}

float calculateAverage(record array[])
{
    float average;
    float sum = 0;

    for (int i = 0; i < 15; i++)
    {
        sum += array[i].price;
    }

    average = sum / 15;

    return average;
}

void display(record array[], float average)
{

    printf("***********************************************\n");
    printf("*             AVERAGE PRICE                   *\n");
    printf("***********************************************\n");

    printf("\n          The average price is: %.2f\n", average);

    printf("***********************************************\n");
    printf("*         STORES WITH PRICES BELOW AVERAGE     *\n");
    printf("***********************************************\n");

    for (int i = 0; i < 15; i++)
    {
        if (array[i].price < average)
        {
            printf("Store name: %s | Store phone: %.2f\n", array[i].name, array[i].phone);
        }
    }
}

int main(void)
{
    record *registrationArray;
    float average;

    registrationArray = registration();

    average = calculateAverage(registrationArray);

    display(registrationArray, average);

    free(registrationArray);

    return 0;
}
