import java.util.*;

public class W6Q2 {
    private int V; // number of vertices
    private LinkedList<Integer>[] adjList; // adjacency list

    public W6Q2(int v) {
        V = v;
        adjList = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adjList[i] = new LinkedList<>();
        }
    }

    public void addEdge(int u, int v) {
        adjList[u].add(v);
        adjList[v].add(u); // for undirected graph
    }

    public boolean isBipartite() {
        int[] color = new int[V]; // array to store colors for vertices
        Arrays.fill(color, -1); // initialize colors as -1 (unvisited)

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) { // unvisited vertex
                if (!bfs(i, color)) {
                    return false; // graph is not bipartite
                }
            }
        }
        return true; // graph is bipartite
    }

    private boolean bfs(int src, int[] color) {
        color[src] = 1; // mark the source vertex with color 1

        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);

        while (!queue.isEmpty()) {
            int u = queue.poll();

            for (int v : adjList[u]) {
                if (color[v] == -1) { // unvisited vertex
                    color[v] = 1 - color[u]; // assign alternate color to adjacent vertex
                    queue.add(v);
                } else if (color[v] == color[u]) {
                    return false; // same color adjacent vertices found, not bipartite
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        int V = sc.nextInt();
        W6Q2 graph = new W6Q2(V);
        System.out.println("Enter the adjacency list of the graph:");
        for (int u = 0; u < V; u++) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int v = sc.nextInt();
                graph.addEdge(u, v);
            }
        }

        if (graph.isBipartite()) {
            System.out.println("Yes Bipartite");
        } else {
            System.out.println("Not Bipartite");
        }
        sc.close();
    }
}
