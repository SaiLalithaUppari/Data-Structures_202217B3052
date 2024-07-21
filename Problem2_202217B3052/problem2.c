#include <stdio.h>

#define MAX_TERMS 10

// Define a structure to represent a polynomial term
struct poly {
    int coeff;  // Coefficient of the term
    int expo;   // Exponent of the term
};

// Function prototypes
int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int);

int main() {
    struct poly p1[MAX_TERMS], p2[MAX_TERMS], p3[MAX_TERMS];
    int t1, t2, t3;

    // Read and display the first polynomial
    t1 = readPoly(p1);
    printf("\nFirst polynomial: ");
    displayPoly(p1, t1);

    // Read and display the second polynomial
    t2 = readPoly(p2);
    printf("\nSecond polynomial: ");
    displayPoly(p2, t2);

    // Add two polynomials and display the resultant polynomial
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\nResultant polynomial after addition: ");
    displayPoly(p3, t3);

    printf("\n");
    return 0;
}

// Function to read polynomial terms from the user
int readPoly(struct poly p[]) {
    int numTerms, i;
    printf("\nEnter the total number of terms in the polynomial: ");
    scanf("%d", &numTerms);
    printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < numTerms; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the Exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }
    return numTerms;
}

// Function to add two polynomials
int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }

    // Copy remaining terms from p1
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    // Copy remaining terms from p2
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }

    return k; // Number of terms in the resultant polynomial
}

// Function to display a polynomial
void displayPoly(struct poly p[], int numTerms) {
    int i;
    for (i = 0; i < numTerms - 1; i++) {
        printf("%d(x^%d) + ", p[i].coeff, p[i].expo);
    }
    printf("%d(x^%d)", p[numTerms - 1].coeff, p[numTerms - 1].expo);
}
