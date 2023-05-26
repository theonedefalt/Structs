#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    char name[80];
    int birthday_day;
    int birthday_month;
} record;

record* funcRegister() {
    record* registerData = malloc(40 * sizeof(record));

    for (int i = 0; i < 40; i++) {
        printf("Enter the name: ");
        scanf("%s", registerData[i].name);
        printf("Enter the birthday day: ");
        scanf("%d", &registerData[i].birthday_day);
        printf("Enter the birthday month: ");
        scanf("%d", &registerData[i].birthday_month);
    }

    return registerData;
}

void PrintData(record array[]) {
    for (int i = 0; i < 40; i++) {
        printf("Name: %s | Birthday Day: %d | Birthday Month: %d\n", array[i].name, array[i].birthday_day, array[i].birthday_month);
    }
}

int main(void) {
    record* registrationArray;

    registrationArray = funcRegister();

    PrintData(registrationArray);

    free(registrationArray);
    return 0;
}
