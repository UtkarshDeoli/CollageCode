#include <iostream>

#include <climits>
using namespace std;
#define INF INT_MAX
#define MAXN 100 // Maximum number of vertices
// Function to compute the shortest distances between all pairs of vertices 
void floydWarshall(int graph[MAXN][MAXN], int N)
{
    int dist[MAXN][MAXN];
    // Initialize the distance matrix with the values from the graph
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
    // Compute the shortest distances
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // If vertex k is on the shortest path from i to j, update the distance
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout << "Shortest distance matrix: " << endl;
    // Print the shortest distance matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int N; // Number of vertices
    cin >> N;
    int graph[MAXN][MAXN];
    // Input the graph
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }
    floydWarshall(graph, N);
    return 0;
}