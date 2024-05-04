#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

struct Edge {
    int source, destination, weight;
};

void BellmanFord(int graph[MAX_EDGES][3], int vertices, int edges, int source) {
    int distance[MAX_VERTICES];
    for (int i = 0; i < vertices; i++)
        distance[i] = INT_MAX;
    distance[source] = 0;
    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }
    for (int i = 0; i < edges; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; ++i)
        printf("%d \t\t %d\n", i, distance[i]);
}

int main() {
    int vertices = 5; 
    int edges = 8; 
    int graph[MAX_EDGES][3] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    int source = 0; 

    BellmanFord(graph, vertices, edges, source);

    return 0;
}
