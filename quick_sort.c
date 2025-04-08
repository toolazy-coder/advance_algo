#include <stdio.h>

// Swap function for float values
void interch(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

// Partition function based on given pseudocode
int partition(float a[], int m, int n) {
    float key = a[m];
    int i = m;
    int j = n + 1;

    while (1) {
        // Move i forward until a[i] > key
        do {
            i++;
        } while (i <= n && a[i] < key);

        // Move j backward until a[j] < key
        do {
            j--;
        } while (a[j] > key);

        if (i < j) {
            interch(&a[i], &a[j]);
        } else {
            break;
        }
    }

    interch(&a[m], &a[j]);  // Place pivot in correct position
    return j;
}

// Quick Sort function
void Qsort(float a[], int m, int n) {
    if (m < n) {
        int j = partition(a, m, n);
        Qsort(a, m, j - 1);   // Sort left subarray
        Qsort(a, j + 1, n);   // Sort right subarray
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

    Qsort(a, 0, n - 1);  // Call Quick Sort

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }

    return 0;
}
