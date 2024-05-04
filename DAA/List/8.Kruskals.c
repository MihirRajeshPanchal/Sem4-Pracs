#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODES 9
#define INF INT_MAX

int adj[NODES][NODES] = {

	{0, 4, 0, 0, 0, 0, 0, 8, 0},
	{4, 0, 8, 0, 0, 0, 0, 11, 0},
	{0, 8, 0, 7, 0, 4, 0, 0, 2},
	{0, 0, 7, 0, 9, 14, 0, 0, 0},
	{0, 0, 0, 9, 0, 10, 0, 0, 0},
	{0, 0, 4, 14, 10, 0, 2, 0, 0},
	{0, 0, 0, 0, 0, 2, 0, 1, 6},
	{8, 11, 0, 0, 0, 0, 1, 0, 7},
	{0, 0, 2, 0, 0, 0, 6, 7, 0}
};

struct Edge {
    int src, dest, weight;
};

int parent[NODES];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionOp(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void *a, const void *b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

void Kruskal(struct Edge edges[], int totalEdges) {
    int edgeCount = 0;
    int totalCost = 0;

    qsort(edges, totalEdges, sizeof(struct Edge), compare);

    for (int i = 0; i < NODES; i++)
        parent[i] = i;

    printf("Minimum Spanning Tree: \n");

    for (int i = 0; i < totalEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int srcParent = find(src);
        int destParent = find(dest);

        if (srcParent != destParent) {
            printf("%c - %c: %d\n", 'a' + src, 'a' + dest, edges[i].weight);
            totalCost += edges[i].weight;
            unionOp(srcParent, destParent);
            edgeCount++;
        }

        if (edgeCount == NODES - 1)
            break;
    }

    printf("Total Cost: %d\n", totalCost);
}

int main() {
    struct Edge edges[NODES * NODES];
    int edgeIndex = 0;

    for (int i = 0; i < NODES; i++) {
        for (int j = i + 1; j < NODES; j++) {
            if (adj[i][j] != 0) {
                edges[edgeIndex].src = i;
                edges[edgeIndex].dest = j;
                edges[edgeIndex].weight = adj[i][j];
                edgeIndex++;
            }
        }
    }
    Kruskal(edges, edgeIndex);
    return 0;
}
