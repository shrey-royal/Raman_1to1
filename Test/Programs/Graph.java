import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Graph {
    int V;
    Node[] adjList;

    Graph(int vertices) {
        this.V = vertices;
        this.adjList = new Node[V];
        for (int i = 0; i < V; i++) {
            adjList[i] = null;
        }
    }

    void addEdge(int src, int dest) {
        Node newNode = new Node(dest);
        newNode.next = adjList[src];
        adjList[src] = newNode;


        //for undirected graph
        newNode = new Node(src);
        newNode.next = adjList[dest];
        adjList[dest] = newNode;
    }

    void printGraph() {
        System.out.println("Adjancency List: ");
        for(int i = 0; i < V; i++) {
            Node temp = adjList[i];
            System.out.print(i + " -> ");
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    void DFSUtil(int v, boolean[] visited) {
        visited[v] = true;
        System.out.print(v + " ");
        Node temp = adjList[v];
        while (temp != null) {
            int n = temp.data;
            if(!visited[n]) {
                DFSUtil(n, visited);
            }
            temp = temp.next;
        }
    }

    void DFS(int startVertex) {
        boolean[] visited = new boolean[V];
        System.out.println("Depth-First Search: ");
        DFSUtil(startVertex, visited);
        System.out.println();
    }

    void BFS(int startVertex) {
        boolean[] visited = new boolean[V];
        System.out.println("Bredth-First Search: ");

        int[] queue = new int[V];
        int front = 0, rear = -1;

        visited[startVertex] = true;
        queue[++rear] = startVertex;

        while (front <= rear) {
            int v = queue[front++];
            System.out.print(v + " ");

            Node temp = adjList[v];
            while(temp != null) {
                int n = temp.data;
                if(!visited[n]) {
                    visited[n] = true;
                    queue[++rear]= n;
                }
                temp = temp.next;
            }
        }
        System.out.println();
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        int V = sc.nextInt();
        sc.close();
        Graph graph = new Graph(V);

        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        graph.addEdge(3, 4);
        graph.addEdge(4, 0);

        graph.printGraph();

        graph.DFS(0);
    }
}