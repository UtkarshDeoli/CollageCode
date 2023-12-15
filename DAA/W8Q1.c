#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    int source, destination, cost;
} Edge;

typedef struct {
    int numVertices, numEdges;
    Edge edges[MAX];
} Graph;

Graph createGraph(int numVertices, int numEdges) {
    Graph graph;
    graph.numVertices = numVertices;
    graph.numEdges = numEdges;
    return graph;
}

void addEdge(Graph* graph, int source, int destination, int cost) {
    graph->edges[graph->numEdges].source = source;
    graph->edges[graph->numEdges].destination = destination;
    graph->edges[graph->numEdges].cost = cost;
    graph->numEdges++;
}

int findMinCostVertex(int costs[], bool visited[], int numVertices) {
    int minCost = __INT_MAX__;
    int minCostVertex;

    for (int v = 0; v < numVertices; v++) {
        if (!visited[v] && costs[v] < minCost) {
            minCost = costs[v];
            minCostVertex = v;
        }
    }

    return minCostVertex;
}

void printMinCost(int costs[], int numVertices) {
    int minCost = 0;

    for (int i = 0; i < numVertices; i++) {
        minCost += costs[i];
    }

    printf("Minimum cost to connect cities: %d\n", minCost);
}

void findMinimumCost(Graph* graph) {
    int numVertices = graph->numVertices;
    int costs[MAX];
    bool visited[MAX];

    for (int i = 0; i < numVertices; i++) {
        costs[i] = __INT_MAX__;
        visited[i] = false;
    }

    costs[0] = 0;

    for (int i = 0; i < numVertices - 1; i++) {
        int currentVertex = findMinCostVertex(costs, visited, numVertices);
        visited[currentVertex] = true;

        for (int j = 0; j < graph->numEdges; j++) {
            int source = graph->edges[j].source;
            int destination = graph->edges[j].destination;
            int cost = graph->edges[j].cost;

            if (source == currentVertex && !visited[destination] && cost < costs[destination]) {
                costs[destination] = cost;
            }
        }
    }

    printMinCost(costs, numVertices);
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of cities: ");
    scanf("%d", &numVertices);
    numEdges = numVertices - 1;

    Graph graph = createGraph(numVertices, numEdges);

    printf("Enter the details of each road:\n");

    for (int i = 0; i < numEdges; i++) {
        int source, destination, cost;
        printf("Road %d:\n", i + 1);
        printf("Source city: ");
        scanf("%d", &source);
        printf("Destination city: ");
        scanf("%d", &destination);
        printf("Cost: ");
        scanf("%d", &cost);
        addEdge(&graph, source, destination, cost);
    }

    findMinimumCost(&graph);

    return 0;
}
