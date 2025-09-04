#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_LEN 50

char titles[MAX_BOOKS][MAX_LEN];
char auteurs[MAX_BOOKS][MAX_LEN];
int quantities[MAX_BOOKS];
float prices[MAX_BOOKS];

int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter the title of the book: ");
    getchar(); 
    fgets(titles[bookCount], MAX_LEN, stdin);
    titles[bookCount][strcspn(titles[bookCount], "\n")] = '\0';

    printf("Enter the quantity of the book: ");
    scanf("%d", &quantities[bookCount]);

    printf("Enter the price of the book: ");
    scanf("%f", &prices[bookCount]);

    printf("Enter the author of the book: ");
    getchar(); // consume leftover newline
    fgets(auteurs[bookCount], MAX_LEN, stdin);
    auteurs[bookCount][strcspn(auteurs[bookCount], "\n")] = '\0'; // remove newline

    printf("The book added successfully.\n");

    bookCount++;
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("Displaying all books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book #%d\n", i + 1);
        printf("Title: %s\n", titles[i]);
        printf("Quantity: %d\n", quantities[i]);
        printf("Price: %.2f\n", prices[i]);
        printf("Author: %s\n\n", auteurs[i]);
    }
}

void updateBook() {
    char searchtitle[MAX_LEN];

    printf("Enter the title of the book you want to update : ");
    getchar(); 
    fgets(searchtitle, MAX_LEN, stdin);
    searchtitle[strcspn(searchtitle, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], searchtitle) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &quantities[i]);
            printf("The book updated successfully.\n");
            return;
        }
    }

    printf("The book not found!\n");
}

void deleteBook() {
    char searchtitle[MAX_LEN];

    printf("Enter the title of the book you're want to delete : ");
    getchar(); 
    fgets(searchtitle, MAX_LEN, stdin);
    searchtitle[strcspn(searchtitle, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], searchtitle) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                strcpy(titles[j], titles[j + 1]);
                quantities[j] = quantities[j + 1];
                prices[j] = prices[j + 1];
                strcpy(auteurs[j], auteurs[j + 1]);
            }
            bookCount--;
            printf("Book deleted!\n");
            return;
        }
    }
    printf("The book not found!\n");
}

void calculBooks(){
    printf("the book you have on your Library is : %d", bookCount);
}

int main() {
    int choice;

    while (1) {
        printf("\n---- Library Menu ----\n");
        printf("1. Add a Book\n");
        printf("2. Display Books\n");
        printf("3. Update a Book\n");
        printf("4. Delete a Book\n");
        printf("5. list books\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                calculBooks();
                break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
