/*
Given a directed graph with two vertices ( source and destination). Design an algorithm and
implement it using a program to find the weight of the shortest path from source to destination with
exactly k edges on the path.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int shortestPathWeight(int graph[][100], int src, int dest, int k, int n)
{
    int dp[n][k + 1];
    for (int e = 0; e <= k; e++)
        for (int i = 0; i < n; i++)
            dp[i][e] = INT_MAX;
    dp[src][0] = 0;
    for (int e = 1; e <= k; e++)
        for (int v = 0; v < n; v++)
            for (int w = 0; w < n; w++)
                if (graph[w][v] != 0 && dp[w][e - 1] != INT_MAX)
                    dp[v][e] = min(dp[v][e], graph[w][v] + dp[w][e - 1]);
    return dp[dest][k];
}
int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[100][100];
    printf("Enter the graph input:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    int src, dest;
    printf("Enter the source and destination vertex numbers: ");
    scanf("%d %d", &src, &dest);
    src--;
    dest--;
    int k;
    printf("Enter the number of edges in the path: ");
    scanf("%d", &k);
    int shortestPathWeightt = shortestPathWeight(graph, src, dest, k, n);
    if (shortestPathWeightt == INT_MAX)
        printf("No path of length %d is available.\n", k);
    else
printf("Weight of shortest path from (%d,%d) with %d edges: %d\n",src+1,dest+1,k,shortestPathWeightt);
return 0;
}