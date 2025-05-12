#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesization
void printOptimalParens(int s[][10], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[10][10]; // Minimum number of multiplications
    int s[10][10]; // Split points
    int i, j, k, l;

    // Initialize the main diagonal to 0
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // l is the chain length
    for (l = 2; l < n; l++) {
        for (i = 1; i < n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum number of multiplications: %d\n", m[1][n - 1]);

    printf("Optimal Parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");
}

int main() {
    int n, i;
    int p[10];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter %d dimensions (for %d matrices):\n", n + 1, n);
    for (i = 0; i <= n; i++) {
        printf("p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n + 1);

    return 0;
}
