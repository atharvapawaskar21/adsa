#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

int *A; // Declare A as a pointer
int *B; // Declare B as a pointer
int current_size; // To store the user-defined size

void merge(int lb, int mid, int ub) {
    int i, j, k;
    i = lb;
    j = mid + 1;
    k = lb;

    while (i <= mid && j <= ub) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= ub) {
        B[k] = A[j];
        j++;
        k++;
    }

    for (k = lb; k <= ub; k++) {
        A[k] = B[k];
    }
}

void merge_sort(int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        merge_sort(lb, mid);
        merge_sort(mid + 1, ub);
        merge(lb, mid, ub);
    }
}

int main() {
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &current_size);

    if (current_size <= 0) {
        printf("Number of elements must be positive.\n");
        return 1; // Indicate an error
    }

    // Allocate memory dynamically for arrays A and B
    A = (int *)malloc(current_size * sizeof(int));
    B = (int *)malloc(current_size * sizeof(int));

    // Check if memory allocation was successful
    if (A == NULL || B == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        // Free any allocated memory before exiting
        free(A);
        free(B);
        return 1;
    }

    printf("Enter %d elements:\n", current_size);
    for (int i = 0; i < current_size; i++) {
        printf("Element[%d]: ", i);
        scanf("%d", &A[i]);
    }

    merge_sort(0, current_size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < current_size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(A);
    free(B);

    return 0;
}
