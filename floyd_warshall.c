#include <stdio.h>

#define INF 1000000  // Use a large number to represent infinity
#define MAX 100      // Maximum number of vertices

void floydWarshall(int W[MAX][MAX], int n) {
    int D[MAX][MAX];
    int i, j, k;

    // Step 1: Initialize D with W
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            D[i][j] = W[i][j];
        }
    }

    // Step 2: Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    // Step 3: Print the result
    printf("\nAll-pairs shortest path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", D[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int W[MAX][MAX];
    int n, i, j;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    floydWarshall(W, n);

    return 0;
}
