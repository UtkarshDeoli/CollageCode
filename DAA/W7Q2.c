/*
Design an algorithm and implement it using a program to solve previous question's problem using
Bellman- Ford's shortest path algorithm.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Edge
{
    int src;
    int dest;
    int weight;
};
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" %d", j + 1);
}
void printSolution(int dist[], int parent[], int src, int n)
{
    printf("Friend\tDistance\tPath\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d", i + 1, dist[i], src + 1);
        printPath(parent, i);
        printf("\n");
    }
}
void bellmanFord(int graph[][100], int src, int n)
{
    int dist[100];
    int parent[100];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
    printSolution(dist, parent, src, n);
}
int main()
{
    int n;
    printf("Enter the number of friends' locations: ");
    scanf("%d", &n);
    int graph[100][100];
    printf("Enter the graph input:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    int akshayHouse;
    printf("Enter Akshay's house location: ");
    scanf("%d", &akshayHouse);
    akshayHouse--;
    bellmanFord(graph, akshayHouse, n);
    return 0;
}