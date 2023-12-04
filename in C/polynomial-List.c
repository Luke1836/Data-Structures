#include <stdio.h>
#include <stdlib.h>
// Define a Node structure to represent terms in a polynomial
struct Node {
int coefficient;
int exponent;
struct Node *next;
};

// Function to insert a term into a polynomial
struct Node *insertTerm(struct Node* head, int coefficient, int exponent) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->coefficient = coefficient;
newNode->exponent = exponent;
newNode->next = NULL;
if (head == NULL) {
return newNode;
}
struct Node *curr = head;
while (curr->next != NULL) {
curr = curr->next;
}
curr->next = newNode;
return head;
}
// Function to display a polynomial
void displayPolynomial(struct Node *head) {
struct Node *curr = head;
while (curr != NULL) {
printf("%dx^%d ", curr->coefficient, curr->exponent);
if (curr->next != NULL) {
printf("+ ");
}
curr = curr->next;
}
printf("\n");
}
// Function to add two polynomials
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
struct Node *result = NULL;
struct Node *curr1 = poly1, *curr_min;
struct Node *curr2 = poly2, *curr_max;
int n1,n2, max;
n1 = n2 = 0;
while(curr1 != NULL)
{
n1++;
curr1 = curr1->next;
}
while(curr2 != NULL)
{
n2++;
curr2 = curr2->next;
}
if(n1 > n2)
{ curr_max = poly1;
curr_min = poly2;
}
else {

curr_max = poly2;
curr_min = poly1;
}
while (curr_max != NULL) {
int sumCoeff = 0;
int coeff1 = (curr_max != NULL) ? curr_max->coefficient : 0;
int exp1 = (curr_max != NULL) ? curr_max->exponent : 0;
int coeff2 = (curr_min != NULL) ? curr_min->coefficient : 0;
int exp2 = (curr_min != NULL) ? curr_min->exponent : 0;
if(exp1>exp2)
{
result = insertTerm(result, coeff1, exp1);
curr_max = curr_max->next;
}
else if(exp1<exp2)
{
result = insertTerm(result, coeff2, exp2);
curr_min = curr_min->next;
}
else {
sumCoeff = coeff1 + coeff2;
result = insertTerm(result, sumCoeff, exp1);
curr_max = curr_max->next;
curr_min = curr_min->next;
}
}
printf("%d %d\n", result->coefficient, result->exponent);
return result;
}
// Function to multiply two polynomials
struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2) {
struct Node *result = NULL;
struct Node *curr1 = poly1;
while (curr1 != NULL) {
struct Node* curr2 = poly2;
while (curr2 != NULL) {
int productCoeff = curr1->coefficient * curr2->coefficient;
int sumExp = curr1->exponent + curr2->exponent;
result = insertTerm(result, productCoeff, sumExp);
curr2 = curr2->next;
}
curr1 = curr1->next;
}
return result;
}
// Function to free the memory allocated for a polynomial
void freePolynomial(struct Node *head) {
struct Node *curr = head;
while (curr != NULL) {
struct Node *temp = curr;

curr = curr->next;
free(temp);
}
}
int main() {
struct Node *poly1 = NULL;
struct Node *poly2 = NULL;
// Input first polynomial
int coeff, exp;
printf("Enter the first polynomial (enter coefficient-0 and exponent-0 at the end):\n");
while (1) {
printf("Enter coefficient and exponent: ");
scanf("%d %d", &coeff, &exp);
if (coeff == 0 && exp == 0) {
break;
}
poly1 = insertTerm(poly1, coeff, exp);
}
// Input second polynomial
printf("\nEnter the second polynomial (enter coefficient-0 and exponent-0 at the end):\n");
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

// Calculate and display the product of the two polynomials
struct Node *productResult = multiplyPolynomials(poly1, poly2);
printf("\nProduct of the Polynomials: ");
displayPolynomial(productResult);
// Calculate and display the sum of the two polynomials
struct Node *sumResult = addPolynomials(poly1, poly2);
printf("\nSum of the Polynomials: ");
displayPolynomial(sumResult);
// Free the memory allocated for the linked lists
freePolynomial(poly1);
freePolynomial(poly2);
freePolynomial(sumResult);
freePolynomial(productResult);
return 0;
}