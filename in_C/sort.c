#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Function prototypes
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void heapSort(int arr[], int n);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

// ... (Other functions and declarations)

int main() {
    int n;
    int arr[MAX_SIZE];
    FILE *file;
    int count = 0;

    // Open the file in read mode
    file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    while (fscanf(file, "%d", &arr[count]) == 1) {
        count++;
        if (count >= MAX_SIZE) {
            break;
        }
    }

    fclose(file);
    n = count;  
    printf("Original array:\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t", arr[i]);
        }

    printf("\nSorting Algorithms:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Heap Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertionSort(arr, n);
                break;
            case 2:
                selectionSort(arr, n);
                break;
            case 3:
                heapSort(arr, n);
                break;
            case 4:
                mergeSort(arr, 0, n - 1);
                break;
            case 5:
                quickSort(arr, 0, n - 1);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        printf("Sorted array:\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap them and continue to heapify
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}
void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0; 
    j = 0; 
    k = low; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; 
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

