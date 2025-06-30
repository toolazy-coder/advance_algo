#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 100
int visited[MAX];

// Print the current augmenting path
void printPath(int parent[], int s, int t) {
    int path[MAX], path_index = 0;
    int v = t;

    // Backtrack from sink to source using parent[]
    while (v != -1) {
        path[path_index++] = v;
        v = parent[v];
    }

    // Print path in correct order (from source to sink)
    printf("Augmenting path: ");
    for (int i = path_index - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i != 0) printf(" -> ");
    }
    printf("\n");
}

// DFS to find path from s to t
int dfs(int rGraph[MAX][MAX], int u, int t, int parent[], int V) {
    int v;
    visited[u] = 1;
    if (u == t)
        return 1;

    for (v = 0; v < V; v++) {
        if (!visited[v] && rGraph[u][v] > 0) {
            parent[v] = u;
            if (dfs(rGraph, v, t, parent, V))
                return 1;
        }
    }
    return 0;
}

// Ford-Fulkerson algorithm
int fordFulkerson(int graph[MAX][MAX], int s, int t, int V) {
    int u, v;
    int rGraph[MAX][MAX];
    int parent[MAX];
    int max_flow = 0;
    int path_flow, iteration = 1;

    // Initialize residual graph
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    while (1) {
        memset(visited, 0, sizeof(visited));
        memset(parent, -1, sizeof(parent));

        if (!dfs(rGraph, s, t, parent, V))
            break;

        // Find bottleneck capacity
        path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (rGraph[u][v] < path_flow)
                path_flow = rGraph[u][v];
        }

        // Update residual graph
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        printf("\nIteration %d:\n", iteration++);
        printPath(parent, s, t);
        printf("Flow added in this path: %d\n", path_flow);

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int V, s, t;
    int graph[MAX][MAX];
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the capacity matrix (%d x %d):\n", V, V);
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("Capacity from %d to %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", V - 1);
    scanf("%d", &s);
    printf("Enter sink vertex (0 to %d): ", V - 1);
    scanf("%d", &t);

    int maxFlow = fordFulkerson(graph, s, t, V);

    printf("\nThe maximum possible flow is: %d\n", maxFlow);
    return 0;
}
