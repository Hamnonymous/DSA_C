
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
	int numVertices;
	int adj[MAX][MAX];
};

struct Graph* createGraph(int vertices) {
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

	graph->numVertices = vertices;

	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			graph->adj[i][j] = 0;
		}
	}
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
	graph->adj[src][dest] = 1;
	graph->adj[dest][src] = 1;
}

void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
	visited[vertex] = 1;
	printf("%d ", vertex);
	for (int i = 0; i < graph->numVertices; i++) {
		if (graph->adj[vertex][i] == 1 && !visited[i]) {
			DFSUtil(graph, i, visited);
		}
	}
}

void DFS(struct Graph* graph, int startVertex) {
	int visited[MAX] = {0};
	printf("DFS Traversal starting from vertex %d:\n", startVertex);
	DFSUtil(graph, startVertex, visited);
	printf("\n");
}

void BFS(struct Graph* graph, int startVertex) {
	int visited[MAX] = {0};
	int queue[MAX], front = 0, rear = 0;
	visited[startVertex] = 1;
	queue[rear++] = startVertex;
	printf("BFS Traversal starting from vertex %d:\n", startVertex);
	while (front < rear) {
		int currentVertex = queue[front++];
		printf("%d ", currentVertex);
		for (int i = 0; i < graph->numVertices; i++) {
			if (graph->adj[currentVertex][i] == 1 && !visited[i]) {
				visited[i] = 1;
				queue[rear++] = i;
			}
		}
	}
	printf("\n");
}

int main() {
	int vertices, edges, src, dest;
	printf("Enter the number of vertices: ");
	scanf("%d", &vertices);
	struct Graph* graph = createGraph(vertices);
	printf("Enter the number of edges: ");
	scanf("%d", &edges);
	printf("Enter the edges (src dest):\n");
	for (int i = 0; i < edges; i++) {
		scanf("%d %d", &src, &dest);
		addEdge(graph, src, dest);
	}
	int startVertex;
	printf("Enter the starting vertex for DFS and BFS: ");
	scanf("%d", &startVertex);
	DFS(graph, startVertex);
	BFS(graph, startVertex);

	free(graph);
	return 0;
}
