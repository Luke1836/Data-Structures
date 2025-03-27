#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

void convertToTuple(int matrix[][10], struct Element tuple[], int rows, int cols, int *count) {
    *count = 0;
    int c = *count;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                tuple[c].row = i;
                tuple[c].col = j;
                tuple[c].value = matrix[i][j];
                c++;
            }
        }
    }
    *count = c;
}

void displayTuple(struct Element tuple[], int *size) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < *size; i++) {
        if(tuple[i].value != 0)
            printf("%d\t%d\t%d\n", tuple[i].row, tuple[i].col, tuple[i].value);
    }
}

void findTranspose(struct Element tuple[], int *size, struct Element transpose[]) {
    for (int i = 0; i < *size; i++) {
        transpose[i].row = tuple[i].col;
        transpose[i].col = tuple[i].row;
        transpose[i].value = tuple[i].value;
    }
}

void findSum(struct Element tuple1[], int *size1, struct Element tuple2[], int *size2, struct Element sum[]) {
    int i = 0, j = 0, k = 0;
    int s1 = *size1; int s2 = *size2;
    while (i < s1 && j < s2) {
        if (tuple1[i].row < tuple2[j].row) {
            sum[k] = tuple1[i];
            i++;
        } else if (tuple1[i].row > tuple2[j].row) {
            sum[k] = tuple2[j];
            j++;
        } else {
            if (tuple1[i].col < tuple2[j].col) {
                sum[k] = tuple1[i];
                i++;
            } else if (tuple1[i].col > tuple2[j].col) {
                sum[k] = tuple2[j];
                j++;
            } else {
                sum[k].row = tuple1[i].row;
                sum[k].col = tuple1[i].col;
                sum[k].value = tuple1[i].value + tuple2[j].value;
                i++;
                j++;
            }
        }
        k++;
    }
    while (i < s1) {
        sum[k++] = tuple1[i++];
    }
    while (j < s2) {
        sum[k++] = tuple2[j++];
    }
    // Fill the remaining elements of sum with zeros
    while (k < (s1 + s2)) {
        sum[k].row = 0;
        sum[k].col = 0;
        sum[k].value = 0;
        k++;
    }
    *size1 = k;
}


int main() {
    int r1, col1, r2, col2, i, j;

    printf("Enter number of rows and columns of the first matrix: \n");
    scanf("%d %d", &r1, &col1);

    printf("Enter number of rows and columns of the second matrix: \n");
    scanf("%d %d", &r2, &col2);

    int matrix1[10][10], matrix2[10][10];
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < col1; j++) {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("The first matrix\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int *c1 = &count1;
    int *c2 = &count2;
    struct Element tuple1[r1 * col1], tuple2[r2 * col2], sum[r1 * col1], transpose[r1 * col1];

    convertToTuple(matrix1, tuple1, r1, col1, c1);
    convertToTuple(matrix2, tuple2, r2, col2, c2);

    printf("Tuple form of first matrix:\n");
    displayTuple(tuple1, c1);

    printf("Tuple form of second matrix:\n");
    displayTuple(tuple2, c2);

    findTranspose(tuple1, c1, transpose);
    printf("Transpose of first matrix:\n");
    displayTuple(transpose, c1);

    if(r1 != r2 || col1 != col2)
    {
        printf("Matrix addition not possible\n");
        return 1;
    }
    findSum(tuple1, c1, tuple2, c2, sum);
    printf("Sum of the two matrices in tuple form:\n");
    displayTuple(sum, c1);

    return 0;
}