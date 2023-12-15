/*After end term examination, Akshay wants to party with his friends. All his friends are living as
paying guest and it has been decided to first gather at Akshay’s house and then move towards party
location. The problem is that no one knows the exact address of his house in the city. Akshay as a
computer science wizard knows how to apply his theory subjects in his real life and came up with
an amazing idea to help his friends. He draws a graph by looking in to location of his house and
his friends’ location (as a node in the graph) on a map. He wishes to find out shortest distance and
path covering that distance from each of his friend’s location to his house and then whatsapp them
this path so that they can reach his house in minimum time. Akshay has developed the program
that implements Dijkstra’s algorithm but not sure about correctness of results. Can you also
implement the same algorithm and verify the correctness of Akshay’s results? (Hint: Print shortest
path and distance from friends’ location to Akshay’s house)*/



import java.util.*;
public class W7Q1 {

    static class Edge {
        int source;
        int destination;
        int weight;

        public Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }

    static class Graph {
        int vertices;
        LinkedList<Edge> [] adjacencylist;

        Graph(int vertices) {
            this.vertices = vertices;
            adjacencylist = new LinkedList[vertices];
            //initialize adjacency lists for all the vertices
            for (int i = 0; i <vertices ; i++) {
                adjacencylist[i] = new LinkedList<>();
            }
        }
    

        public void addEgde(int source, int destination, int weight) {
            Edge edge = new Edge(source, destination, weight);
            adjacencylist[source].addFirst(edge); //for directed graph
        }

        public void printGraph(){
            for (int i = 0; i <vertices ; i++) {
                LinkedList<Edge> list = adjacencylist[i];
                for (int j = 0; j <list.size() ; j++) {
                    System.out.println("vertex-" + i + " is connected to " +
                            list.get(j).destination + " with weight " +  list.get(j).weight);
                }
            }
        }
    }
    public static void main(String args[])
    {
        Scanner scr = new Scanner(System.in);
        System.out.println("Enter Number of vertices :");
        int vertices = scr.nextInt();
        
        int adjMat[][]= new int[vertices][vertices];
        System.out.println("Enter Adjency matrix:");
        for(int i =0; i <vertices ; i++)
        {
            for(int j =0 ; j<vertices;j++)
                adjMat[i][j]=scr.nextInt();
                System.out.println("");
        }
            

            Graph graph = new Graph(vertices);

            for(int i =0; i <vertices ; i++)
            {
                for(int j =0 ; j<vertices;j++)
                {
                    if(adjMat[i][j]!=0)
                    {
                        graph.addEgde(i, j, adjMat[i][j]);
                    }
                }
            }            
            graph.printGraph();
        scr.close();
    }
}

