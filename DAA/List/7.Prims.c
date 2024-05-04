#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define NODES 9
#define INF INT_MAX

int mst[NODES];
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

struct Vertices {
	int dist;
	int parent;
	int visited;
} V[NODES];

struct Graph {
	char nodes[NODES];
	int adjMatrix[NODES][NODES];
} G;

int extractMin() {
	int min = INF;
	int minIndex = -1;
	for (int i = 0; i < NODES; i++) {
		if (!V[i].visited && V[i].dist < min) {
			min = V[i].dist;
			minIndex = i;
		}
	}
	return minIndex;
}


void Prims(int start) {
	for (int i = 0; i < NODES; i++) {
		V[i].dist = INF;
		V[i].parent = -1;
		V[i].visited = 0;
	}
	V[start].dist = 0;
	for (int i = 0; i < NODES; i++) {
		int u = extractMin();
		V[u].visited = 1;
		for (int v = 0; v < NODES; v++) {
			if (G.adjMatrix[u][v] && !V[v].visited && V[v].dist > G.adjMatrix[u][v]) {
				V[v].parent = u;
				V[v].dist = G.adjMatrix[u][v];
			}
		}
	}
	for (int i = 0; i < NODES; i++) {
		mst[i] = V[i].parent;
	}
}

int main() {
	int totalCost = 0;
	for (int i = 0; i < NODES; i++) {
		for (int j = 0; j < NODES; j++) {
			G.adjMatrix[i][j] = adj[i][j];
		}
	}
	for (int i = 0; i < NODES; i++) {
		G.nodes[i] = 'a' + i;
	}
	Prims(0);
	printf("Minimum Spanning Tree: \n");
	for (int i = 0; i < NODES; i++) {
		if (mst[i] != -1) {
			printf("%c - %c: %d\n", G.nodes[mst[i]], G.nodes[i], G.adjMatrix[i][mst[i]]);
			totalCost += G.adjMatrix[i][mst[i]];
		}
	}
	printf("Total Cost: %d\n", totalCost);
	return 0;
}