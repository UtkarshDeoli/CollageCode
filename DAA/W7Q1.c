#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};
struct Node *createNode(int v, int w)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct Node *graph[], int src, int dest, int weight)
{
    struct Node *newNode = createNode(dest, weight);
    newNode->next = graph[src];
    graph[src] = newNode;
}
int minDistance(int dist[], int visited[], int n)
{
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; i++)
        if (visited[i] == 0 && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    return minIndex;
}
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}
void printSolution(int dist[], int parent[], int src, int n)
{
    printf("Friend\tDistance\tPath\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d", i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}
void dijkstra(struct Node *graph[], int src, int n)
{
    int dist[100];
    int visited[100];
    int parent[100];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;
        struct Node *currentNode = graph[u];
        while (currentNode != NULL)
        {
            int v = currentNode->vertex;
            int weight = currentNode->weight;
            if (visited[v] == 0 && dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
            currentNode = currentNode->next;
        }
    }
    printSolution(dist, parent, src, n);
}
int main()
{
    int n;
    printf("Enter the number of friends' locations: ");
    scanf("%d", &n);
    struct Node *graph[100];
    for (int i = 0; i < 100; i++)
        graph[i] = NULL;
    printf("Enter the graph input:\n");
    int src, dest, weight;
    while (1)
    {
        printf("Enter source, destination, and weight (-1 -1 -1 to stop): ");
        scanf("%d %d %d", &src, &dest, &weight);
        if (src == -1 && dest == -1 && weight == -1)
            break;
        addEdge(graph, src, dest, weight);
    }
    int akshayHouse;
    printf("Enter Akshay's house location: ");
    scanf("%d", &akshayHouse);
    dijkstra(graph, akshayHouse, n);
    return 0;
}