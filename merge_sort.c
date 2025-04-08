#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Merge function based on the given pseudocode
void Merge(float a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create temporary arrays
    float L[n1 + 1], R[n2 + 1];
    int i, j, k;

    // Copy data to L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (j = 0; j < n2; j++)
        R[j] = a[q + 1 + j];

    // Sentinel values (larger than any float)
    L[n1] = R[n2] = __FLT_MAX__;

    i = 0;
    j = 0;

    // Merge the arrays back into a[p..r]
    for (k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
    }
}

// Merge sort function based on your pseudocode
void Merge_sort(float a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        Merge_sort(a, p, q);
        Merge_sort(a, q + 1, r);
        Merge(a, p, q, r);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float a[n];

    printf("Enter %d numbers (can be negative and decimal):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    Merge_sort(a, 0, n - 1);  // Call merge sort

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }

    return 0;
}
