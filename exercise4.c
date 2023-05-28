#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1500

typedef struct books {
    int catalog_code;
    char donation;
    char title[80];
    char author_name[80];
    char publisher[80];
    char area[20];
} books;

void registerBooks(books *book, int quantity) {
    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the book's area (Exact Sciences, Humanities, or Biological): ");
        scanf("%s", book[i].area);
        printf("Enter the catalog code of the book: ");
        scanf("%d", &book[i].catalog_code);
        printf("Was the book donated? (Y/N): ");
        scanf(" %c", &book[i].donation);
        printf("Enter the title of the book: ");
        scanf("%s", book[i].title);
        printf("Enter the author's name: ");
        scanf("%s", book[i].author_name);
        printf("Enter the publisher: ");
        scanf("%s", book[i].publisher);
    }
}

void searchBooks(books *book, int quantity) {
    int catalogCode;
    char area[20];

    printf("\nEnter the area of the book you want to access: ");
    scanf("%s", area);

    printf("Enter the catalog code of the book you want to access (Enter '-1' to exit): ");
    scanf("%d", &catalogCode);

    while (catalogCode != -1) {
        int found = 0;

        for (int i = 0; i < quantity; i++) {
            if (book[i].catalog_code == catalogCode && strcmp(book[i].area, area) == 0) {
                printf("\n***Book Information***");
                printf("Area: %s\n", book[i].area);
                printf("Catalog Code: %d\n", book[i].catalog_code);
                printf("Donation: %c\n", book[i].donation);
                printf("Title: %s\n", book[i].title);
                printf("Author's Name: %s\n", book[i].author_name);
                printf("Publisher: %s\n", book[i].publisher);

                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Book not found.");
        }
        printf("\nEnter the catalog code of the book you want to search (-1 to exit): ");
        scanf("%d", &catalogCode);
    }
}

int main(void) {
    books *bookArray = malloc(MAX_BOOKS * sizeof(books));
    int bookQuantity = MAX_BOOKS;

    printf("***********************************************\n");
    printf("*           REGISTER BOOK INFORMATION         *\n");
    printf("***********************************************\n");

    registerBooks(bookArray, bookQuantity);

    printf("***********************************************\n");
    printf("*             SEARCH BOOK INFORMATION         *\n");
    printf("***********************************************\n");

    searchBooks(bookArray, bookQuantity);

    free(bookArray);

    return 0;
}
