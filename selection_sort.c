#include <stdio.h>

// Swap function for floats
void intch(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

// Selection Sort function based on given algorithm
void Selection_sort(float a[], int n) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {       // Note: Arrays in C use 0-based indexing
        j = i;
        for (k = j + 1; k < n; k++) {
            if (a[k] < a[j]) {
                j = k;
            }
        }
        if (i != j) {
            intch(&a[i], &a[j]);  // Swap if a smaller element was found
        }
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float a[n];

    printf("Enter %d numbers :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    Selection_sort(a, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }

    return 0;
}
