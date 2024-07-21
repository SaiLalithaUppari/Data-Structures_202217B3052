#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/* Define the required functions to create a list, insert into the list, 
delete an element from the list, search and display the list */
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0, pos, e, p, i;

void main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        /* The following switch will call the appropriate choice provided by the user */
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n)?: ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');
}

void create() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("\nNumber of elements exceeds the maximum limit of %d\n", MAX);
        n = 0; // reset n to 0
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter the element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    if (n == 0) {
        printf("\nThe list is empty, nothing to delete.\n");
        return;
    }

    printf("\nEnter the position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("\nInvalid location.\n");
    } else {
        for (i = pos - 1; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;

        printf("\nThe elements after deletion:\n");
        display();
    }
}

void search() {
    if (n == 0) {
        printf("\nThe list is empty, nothing to search.\n");
        return;
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value %d is in position %d.\n", e, i + 1);
            return;
        }
    }
    printf("Value %d is not in the list.\n", e);
}

void insert() {
    if (n == MAX) {
        printf("\nThe list is full, cannot insert new element.\n");
        return;
    }

    printf("\nEnter the position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("\nInvalid location.\n");
    } else {
        for (i = n; i >= pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos - 1] = p;
        n++;

        printf("\nThe list after insertion:\n");
        display();
    }
}

void display() {
    if (n == 0) {
        printf("\nThe list is empty.\n");
        return;
    }

    printf("\nThe elements of the list ADT are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", b[i]);
    }
}

