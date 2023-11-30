#include <stdio.h>

typedef struct Term {
    int coefficient;
    int exponent;
} polynomial;

void inputPolynomial(polynomial poly[], int degree) {
    int i;
    for (i = degree; i >= 0; i--) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &(poly[i].coefficient));
        poly[i].exponent = i;
    }
}

int main() {
    int degree1, degree2, i;
    
    // Read the degree of the first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    
    // Read coefficients of the first polynomial
    polynomial poly1[degree1 + 1];
    inputPolynomial(poly1, degree1);
    
    // Read the degree of the second polynomial
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    
    // Read coefficients of the second polynomial
    polynomial poly2[degree2 + 1];
    inputPolynomial(poly2, degree2);
    
    // Calculate the sum of the two polynomials
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;
    polynomial result[maxDegree + 1];
    
    for (i = 0; i <= maxDegree; i++) {
        int coeff1 = (i <= degree1) ? poly1[i].coefficient : 0;
        int coeff2 = (i <= degree2) ? poly2[i].coefficient : 0;
        result[i].coefficient = coeff1 + coeff2;
        result[i].exponent = i;
    }
    
    // Display the first polynomial
    printf("First polynomial: ");
    for (i = degree1; i >= 0; i--) {
        printf("%dx^%d ", poly1[i].coefficient, poly1[i].exponent);
        if (i > 0) {
            printf("+ ");
        }
    }
    printf("\n");
    
    // Display the second polynomial
    printf("Second polynomial: ");
    for (i = degree2; i >= 0; i--) {
        printf("%dx^%d ", poly2[i].coefficient, poly2[i].exponent);
        if (i > 0) {
            printf("+ ");
        }
    }
    printf("\n");
    
    // Display the resultant polynomial
    printf("Resultant polynomial (sum): ");
    for (i = maxDegree; i >= 0; i--) {
        printf("%dx^%d ", result[i].coefficient, result[i].exponent);
        if (i > 0) {
            printf("+ ");
        }
    }
    printf("\n");
    return 0;
}