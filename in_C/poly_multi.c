#include <stdio.h>
#include <stdlib.h>

struct Polynomial {
    int degree;
    int* coefficients;
};

// Function to initialize a polynomial
struct Polynomial initializePolynomial(int degree) {
    struct Polynomial poly;
    poly.degree = degree;
    poly.coefficients = (int*)malloc((degree + 1) * sizeof(int));
    
    // Initialize coefficients to 0
    for (int i = 0; i <= degree; ++i) {
        poly.coefficients[i] = 0;
    }

    return poly;
}

// Function to input a polynomial
struct Polynomial inputPolynomial() {
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    struct Polynomial poly = initializePolynomial(degree);

    printf("Enter the coefficients starting from the highest degree term:\n");
    for (int i = degree; i >= 0; --i) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly.coefficients[i]);
    }

    return poly;
}

// Function to multiply two polynomials
struct Polynomial multiplyPolynomials(struct Polynomial poly1, struct Polynomial poly2) {
    int resultDegree = poly1.degree + poly2.degree;
    struct Polynomial result = initializePolynomial(resultDegree);

    for (int i = 0; i <= poly1.degree; ++i) {
        for (int j = 0; j <= poly2.degree; ++j) {
            result.coefficients[i + j] += poly1.coefficients[i] * poly2.coefficients[j];
        }
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Polynomial poly) {
    printf("Polynomial: ");
    for (int i = poly.degree; i >= 0; --i) {
        printf("%dx^%d", poly.coefficients[i], i);
        if (i > 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Polynomial poly1, poly2, result;

    printf("Enter the first polynomial:\n");
    poly1 = inputPolynomial();

    printf("Enter the second polynomial:\n");
    poly2 = inputPolynomial();

    result = multiplyPolynomials(poly1, poly2);

    printf("Result of polynomial multiplication:\n");
    displayPolynomial(result);

    // Free memory allocated for coefficients
    free(poly1.coefficients);
    free(poly2.coefficients);
    free(result.coefficients);

    return 0;
}
