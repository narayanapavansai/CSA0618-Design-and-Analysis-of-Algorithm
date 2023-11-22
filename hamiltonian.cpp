#include <stdio.h>
#include <stdbool.h>

#define V 10 

void printSolution(int path[], int vertices);

bool isSafe(int v, bool graph[V][V], int path[], int pos, int vertices) {
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCycleUtil(bool graph[V][V], int path[], int pos, int vertices) {
    if (pos == vertices) {
    
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < vertices; v++) {
        if (isSafe(v, graph, path, pos, vertices)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1, vertices) == true)
                return true;

            path[pos] = -1; 
        }
    }

    return false;
}

void hamiltonianCycle(bool graph[V][V], int vertices) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; 

    if (hamiltonianCycleUtil(graph, path, 1, vertices) == false) {
        printf("Hamiltonian Cycle does not exist\n");
        return;
    }

    printf("Hamiltonian Cycle exists: \n");
    printSolution(path, vertices);
}

void printSolution(int path[], int vertices) {
    for (int i = 0; i < vertices; i++)
        printf("%d ", path[i]);
    printf("%d ", path[0]);
    printf("\n");
}

int main() {
    int vertices;

    printf("Enter the number of vertices in the graph (maximum 10): ");
    scanf("%d", &vertices);

    bool graph[V][V];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    hamiltonianCycle(graph, vertices);

    return 0;
}

