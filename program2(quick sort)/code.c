#include <stdio.h>
#include <stdlib.h>   // for rand() and srand()
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[i + 1], &A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);

    int A[N];

    // Seed random number generator
    srand(time(NULL));

    // Generate random elements
    printf("Generated elements:\n");
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 1000;  // numbers between 0 and 999
        printf("%d ", A[i]);
    }

    clock_t start = clock();

    quickSort(A, 0, N - 1);

    clock_t end = clock();

    printf("\n\nSorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}
