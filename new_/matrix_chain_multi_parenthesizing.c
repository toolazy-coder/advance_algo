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

// Function to print a 2D table
void printTable(const char* name, int table[][10], int n) {
    printf("\n%s Table:\n", name);
    printf("    ");
    for (int j = 1; j < n; j++) {
        printf(" %7d", j);
    }
    printf("\n");

    for (int i = 1; i < n; i++) {
        printf("%3d ", i);
        for (int j = 1; j < n; j++) {
            if (i > j) {
                printf("         ");
            } else if (table[i][j] == INT_MAX) {
                printf("   INF  ");
            } else {
                printf(" %7d", table[i][j]);
            }
        }
        printf("\n");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[10][10]; // Cost table
    int s[10][10]; // Split point table
    int i, j, k, l;

    // Initialize diagonal to 0
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // DP to compute m and s
    for (l = 2; l < n; l++) {
        for (i = 1; i < n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            printf("\nEvaluating m[%d][%d]:\n", i, j);
            for (k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                printf("  Try k=%d: Cost = m[%d][%d](%d) + m[%d][%d](%d) + %d*%d*%d = %d\n",
                    k, i, k, m[i][k], k + 1, j, m[k + 1][j],
                    p[i - 1], p[k], p[j], cost);

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                    printf("    ➤ Update: m[%d][%d] = %d (Split at k=%d)\n", i, j, cost, k);
                }
            }
        }
    }

    // Print final tables
    printTable("Cost (m)", m, n);
    printTable("Split (s)", s, n);

    // Final answer
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
