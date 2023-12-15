import java.util.*;

public class W6Q1 {
    private int V; // number of vertices
    private LinkedList<Integer>[] adjList; // adjacency list

    public W6Q1(int v) {
        V = v;
        adjList = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adjList[i] = new LinkedList<>();
        }
    }

    public void addEdge(int u, int v) {
        adjList[u].add(v); // add edge from u to v
    }

    public boolean isPathExists(int s, int d) {
        boolean[] visited = new boolean[V];
        return dfs(s, d, visited);
    }

    private boolean dfs(int s, int d, boolean[] visited) {
        visited[s] = true; // mark the source vertex as visited
        if (s == d) {
            return true; // if source and destination are the same, then a path exists
        }
        for (int v : adjList[s]) {
            if (!visited[v] && dfs(v, d, visited)) {
                return true; // recursively check for adjacent vertices
            }
        }
        return false; // no path found
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        int V = sc.nextInt();
        W6Q1 graph = new W6Q1(V);
        System.out.println("Enter the adjacency list of the graph:");
        for (int u = 0; u < V; u++) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int v = sc.nextInt();
                graph.addEdge(u, v);
            }
        }
        System.out.print("Enter the source vertex: ");
        int s = sc.nextInt();
        System.out.print("Enter the destination vertex: ");
        int d = sc.nextInt();
        if (graph.isPathExists(s, d)) {
            System.out.println("Yes Path Exists");
        } else {
            System.out.println("No Such Path Exists");
        }
        sc.close();
    }
}
