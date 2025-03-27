#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent Employee
struct Employee {
    int EmpId;
    char FirstName[50];
    char MiddleName[50];
    char LastName[50];
    float Salary;
};

// Function to perform linear search based on EmpId
int linearSearch(struct Employee* employees, int n, int targetEmpId) {
    for (int i = 0; i < n; ++i) {
        if (employees[i].EmpId == targetEmpId) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee* employees = (struct Employee*)malloc(n * sizeof(struct Employee));

    // Input employee details
    for (int i = 0; i < n; ++i) {
        printf("Enter details for Employee %d:\n", i + 1);
        employees[i].EmpId = i + 1;
        printf("Enter First Name: ");
        scanf("%s", employees[i].FirstName);
        printf("Enter Middle Name: ");
        scanf("%s", employees[i].MiddleName);
        printf("Enter Last Name: ");
        scanf("%s", employees[i].LastName);
        printf("Enter Salary: ");
        scanf("%f", &employees[i].Salary);
    }

    // Perform linear search
    int targetEmpId;
    printf("Enter EmpId to search: ");
    scanf("%d", &targetEmpId);

    int result = linearSearch(employees, n, targetEmpId);
    if (result != -1) {
        printf("Employee found:\n");
        printf("EmpId: %d\n", employees[result].EmpId);
        printf("Name: %s %s %s\n", employees[result].FirstName, employees[result].MiddleName, employees[result].LastName);
        printf("Salary: %.2f\n", employees[result].Salary);
    } else {
        printf("Employee with EmpId %d not found.\n", targetEmpId);
    }

    // Free allocated memory
    free(employees);

    return 0;
}
