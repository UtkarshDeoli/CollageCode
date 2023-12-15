import java.util.*;

public class W6Q3 {
    private int V; // number of vertices
    private LinkedList<Integer>[] adjList; // adjacency list

    public W6Q3(int v) {
        V = v;
        adjList = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adjList[i] = new LinkedList<>();
        }
    }

    public void addEdge(int u, int v) {
        adjList[u].add(v); // add edge from u to v
    }

    public boolean isCyclic() {
        boolean[] visited = new boolean[V];
        boolean[] recursionStack = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (isCyclicUtil(i, visited, recursionStack)) {
                return true; // cycle found
            }
        }
        return false; // no cycle found
    }

    private boolean isCyclicUtil(int v, boolean[] visited, boolean[] recursionStack) {
        visited[v] = true;
        recursionStack[v] = true;

        for (int adj : adjList[v]) {
            if (!visited[adj]) {
                if (isCyclicUtil(adj, visited, recursionStack)) {
                    return true; // cycle found in the subtree
                }
            } else if (recursionStack[adj]) {
                return true; // cycle found (back edge)
            }
        }

        recursionStack[v] = false; // remove the vertex from recursion stack
        return false; // no cycle found
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        int V = sc.nextInt();
        W6Q3 graph = new W6Q3(V);
        System.out.println("Enter the adjacency list of the graph:");
        for (int u = 0; u < V; u++) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int v = sc.nextInt();
                graph.addEdge(u, v);
            }
        }

        if (graph.isCyclic()) {
            System.out.println("Yes Cycle Exists");
        } else {
            System.out.println("No Cycle Exists");
        }
        sc.close();
    }
}
