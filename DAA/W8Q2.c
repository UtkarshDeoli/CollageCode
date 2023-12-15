#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int source, destination, weight;
} Edge;

typedef struct {
    int numVertices, numEdges;
    Edge* edges;
} Graph;

typedef struct {
    int parent;
    int rank;
} Subset;

Graph createGraph(int numVertices, int numEdges) {
    Graph graph;
    graph.numVertices = numVertices;
    graph.numEdges = numEdges;
    graph.edges = (Edge*)malloc(numEdges * sizeof(Edge));
    return graph;
}

void addEdge(Graph* graph, int source, int destination, int weight) {
    graph->edges[graph->numEdges].source = source;
    graph->edges[graph->numEdges].destination = destination;
    graph->edges[graph->numEdges].weight = weight;
    graph->numEdges++;
}

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

int findParent(Subset subsets[], int vertex) {
    if (subsets[vertex].parent != vertex)
        subsets[vertex].parent = findParent(subsets, subsets[vertex].parent);
    return subsets[vertex].parent;
}

void unionSubsets(Subset subsets[], int x, int y) {
    int rootX = findParent(subsets, x);
    int rootY = findParent(subsets, y);
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int findMinimumSpanningWeight(Graph* graph) {
    int numVertices = graph->numVertices;
    int numEdges = graph->numEdges;
    Edge* edges = graph->edges;
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    Subset* subsets = (Subset*)malloc(numVertices * sizeof(Subset));
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int minSpanningWeight = 0;
    int edgeCount = 0;
    int i = 0;

    while (edgeCount < numVertices - 1 && i < numEdges) {
        Edge currentEdge = edges[i++];
        int sourceParent = findParent(subsets, currentEdge.source);
        int destParent = findParent(subsets, currentEdge.destination);
        if (sourceParent != destParent) {
            minSpanningWeight += currentEdge.weight;
            unionSubsets(subsets, sourceParent, destParent);
            edgeCount++;
        }
    }

    free(subsets);
    return minSpanningWeight;
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    numEdges = (numVertices * (numVertices - 1)) / 2;

    Graph graph = createGraph(numVertices, numEdges);

    printf("Enter the adjacency matrix of the graph:\n");

    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            int weight;
            printf("Weight between vertex %d and vertex %d: ", i, j);
            scanf("%d", &weight);
            addEdge(&graph, i, j, weight);
        }
    }

    int minSpanningWeight = findMinimumSpanningWeight(&graph);

    printf("Minimum spanning weight: %d\n", minSpanningWeight);

    free(graph.edges);

    return 0;
}
