#include <stdio.h>

// Swap function for floats
void intch(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

// Selection Sort with detailed tracing
void Selection_sort(float a[], int n) {
    int i, j, k, step = 1;
    for (i = 0; i < n - 1; i++) {
        j = i;
        for (k = i + 1; k < n; k++) {
            if (a[k] < a[j]) {
                j = k;
            }
        }

        printf("\nPass %d:\n", step++);
        printf("Minimum element in unsorted part: %.2f at index %d\n", a[j], j);
        if (i != j) {
            printf("Swapping %.2f and %.2f\n", a[i], a[j]);
            intch(&a[i], &a[j]);
        } else {
            printf("No swapping needed as the current element is already the smallest\n");
        }

        // Print array after each pass
        printf("Array after pass %d: ", i + 1);
        for (int m = 0; m < n; m++) {
            printf("%.2f ", a[m]);
        }
        printf("\n");
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float a[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    Selection_sort(a, n);

    printf("\nFinal Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }

    return 0;
}
