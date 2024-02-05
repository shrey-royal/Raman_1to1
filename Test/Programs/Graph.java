class GraphNode {
    int val;
    GraphNode[] neighbors;
    boolean visited;

    GraphNode(int val) {
        this.val = val;
        this.neighbors = new GraphNode[0];
        this.visited = false;
    }
}

public class Graph {
    private GraphNode[] nodes;
    private int size;

    public Graph(int size) {
        this.size = size;
        this.nodes = new GraphNode[size];
    }

    public void addNode(int val) {
        if(val>=0 && val<size && nodes[val] == null) {
            nodes[val] = new GraphNode(val);
        }
    }


    public static void main(String[] args) {
        //
    }
}