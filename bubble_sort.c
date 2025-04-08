#include <stdio.h>

void intch(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble Sort for float array
void Bubble_sort(float a[], int n) {
    int i, j;
    int swapped;
    for (i = 1; i <= n; i++) {
        swapped = 0;
        for (j = 0; j <= n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                intch(&a[j], &a[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float a[n];  // Use float array

    printf("Enter %d numbers :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i]);  // %f for float
    }

    Bubble_sort(a, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", a[i]);  // Print with 2 decimal places
    }

    return 0;
}
