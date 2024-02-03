#include <stdio.h>
#include <stdlib.h>

struct poly {
    int *exponent;
    int *coefficient;
    int degree;
};

struct poly *createPolynomial(int n1) {
    struct poly *p1 = (struct poly *)malloc(sizeof(struct poly));
    p1->coefficient = (int *)malloc(sizeof(int) * (n1 + 1));
    p1->exponent = (int *)malloc(sizeof(int) * (n1 + 1));
    p1->degree = n1;

    return p1;
}

struct poly *insertTerm(struct poly *p1, int i) {
    int coeff;
    printf("Enter the coefficient of the term x^%d: ", i);
    scanf("%d", &coeff);
    p1->exponent[i] = i;
    p1->coefficient[i] = coeff;

    return p1;
}

struct poly *addPolynomial(struct poly *p1, struct poly *p2, struct poly *result, int n1, int n2, int n3) {
    int exp1, exp2, coeff1, coeff2;

    for (int i = 0; i <= n3; i++) {
        coeff1 = (i <= n1) ? p1->coefficient[i] : 0;
        coeff2 = (i <= n2) ? p2->coefficient[i] : 0;

        result->coefficient[i] = coeff1 + coeff2;
        result->exponent[i] = i;
    }

    return result;
}

struct poly *multiplyPolynomial(struct poly *p1, struct poly *p2, struct poly *result, int n1, int n2, int n3)
{
    for (int i = 0; i <= n3; i++)
    {
        result->coefficient[i] = 0;
        result->exponent[i] = 0;
    }

    for (int i = 0; i <= n1; i++)
    { for (int j = 0; j <= n2; j++) 
        {
            result->exponent[i+j] = p1->exponent[i] + p2->exponent[j];
            result->coefficient[i + j] += (p1->coefficient[i] * p2->coefficient[j]);
        }
    }
    return result;
}

void display(struct poly *p, int n) {
    printf("The polynomial: \n");
    for (int i = 0; i <= n; i++) { 
        if(p->coefficient[i] == 0)
            continue;
        printf("%dx^%d + ", p->coefficient[i], p->exponent[i]);
    }
    printf("\n\n\n");
}

int main(void) {
    int n1, n2, n3;
    printf("Enter the value of n1 and n2: ");
    scanf("%d %d", &n1, &n2);

    if (n1 > n2) {
        n3 = n1;
    } else {
        n3 = n2;
    }
    int n4 = n1 + n2;
    struct poly *p1 = createPolynomial(n1), *p2 = createPolynomial(n2), *result = createPolynomial(n3), *result_multi = createPolynomial(n4);

    for (int i = n1; i >= 0; i--)
        p1 = insertTerm(p1, i);
    for (int i = n2; i >= 0; i--)
        p2 = insertTerm(p2, i);

    result = addPolynomial(p1, p2, result, n1, n2, n3);
    result_multi = multiplyPolynomial(p1, p2, result_multi, n1, n2, n4);
    display(p1, n1);
    display(p2, n2);
    display(result, n3);
    display(result_multi, n4);

    free(p1->coefficient);
    free(p1->exponent);
    free(p1);

    free(p2->coefficient);
    free(p2->exponent);
    free(p2);

    free(result->coefficient);
    free(result->exponent);
    free(result);

    free(result_multi->coefficient);
    free(result_multi->exponent);
    free(result_multi);

    return 0;
}
