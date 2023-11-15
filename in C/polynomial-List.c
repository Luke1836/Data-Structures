#include <stdio.h>
#include <stdlib.h>

// Define a Node structure to represent terms in a polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to insert a term into a polynomial
struct Node* insertTerm(struct Node* head, int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to display a polynomial
void displayPolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    struct Node* current1 = poly1;
    struct Node* current2 = poly2;

    while (current1 != NULL || current2 != NULL) {
        int coeff1 = (current1 != NULL) ? current1->coefficient : 0;
        int exp1 = (current1 != NULL) ? current1->exponent : 0;

        int coeff2 = (current2 != NULL) ? current2->coefficient : 0;
        int exp2 = (current2 != NULL) ? current2->exponent : 0;

        int sumCoeff = coeff1 + coeff2;
        result = insertTerm(result, sumCoeff, exp1);

        if (current1 != NULL) {
            current1 = current1->next;
        }
        if (current2 != NULL) {
            current2 = current2->next;
        }
    }

    return result;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* current1 = poly1;

    while (current1 != NULL) {
        struct Node* current2 = poly2;

        while (current2 != NULL) {
            int productCoeff = current1->coefficient * current2->coefficient;
            int sumExp = current1->exponent + current2->exponent;
            result = insertTerm(result, productCoeff, sumExp);

            current2 = current2->next;
        }

        current1 = current1->next;
    }

    return result;
}

// Function to free the memory allocated for a polynomial
void freePolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Input first polynomial
    int coeff, exp;
    printf("Enter the first polynomial (enter 0 0 to end):\n");
    while (1) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        if (coeff == 0 && exp == 0) {
            break;
        }
        poly1 = insertTerm(poly1, coeff, exp);
    }

    // Input second polynomial
    printf("\nEnter the second polynomial (enter 0 0 to end):\n");
    while (1) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        if (coeff == 0 && exp == 0) {
            break;
        }
        poly2 = insertTerm(poly2, coeff, exp);
    }

    // Display the input polynomials
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Calculate and display the sum of the two polynomials
    struct Node* sumResult = addPolynomials(poly1, poly2);
    printf("\nSum of the Polynomials: ");
    displayPolynomial(sumResult);

    // Calculate and display the product of the two polynomials
    struct Node* productResult = multiplyPolynomials(poly1, poly2);
    printf("\nProduct of the Polynomials: ");
    displayPolynomial(productResult);

    // Free the memory allocated for the linked lists
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sumResult);
    freePolynomial(productResult);

    return 0;
}
