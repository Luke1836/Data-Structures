#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_STRING_LENGTH 100

void bubbleSort(char strings[MAX_STRINGS][MAX_STRING_LENGTH], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                // Swap strings
                char temp[MAX_STRING_LENGTH];
                strcpy(temp, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], temp);
            }
        }
    }
}

int binarySearch(char strings[MAX_STRINGS][MAX_STRING_LENGTH], int left, int right, char target[MAX_STRING_LENGTH]) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int compare = strcmp(strings[mid], target);
        if (compare == 0) {
            return mid; // String found at index mid
        }
        if (compare < 0) {
            left = mid + 1; // String is in the right half
        } else {
            right = mid - 1; // String is in the left half
        }
    }
    return -1; // String not found
}

int main() {
    char strings[MAX_STRINGS][MAX_STRING_LENGTH];
    int n = 0; // Number of strings

    FILE *file = fopen("strings.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read strings from the file using fgets to read entire lines
    char line[MAX_STRING_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL && n < MAX_STRINGS) {
        line[strcspn(line, "\n")] = '\0';  // Remove the newline character if present
        strcpy(strings[n], line);
        n++;
    }
    fclose(file);

    // Sort strings and search code (same as before)

    return 0;
}
