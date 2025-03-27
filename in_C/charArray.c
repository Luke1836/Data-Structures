#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    FILE *file;
    int numbers[MAX_SIZE];
    int count = 0;

    // Open the file in read mode
    file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    while (fscanf(file, "%d", &numbers[count]) == 1) {
        count++;
        if (count >= MAX_SIZE) {
            break;
        }
    }

    fclose(file);

    printf("Values read from the file:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
