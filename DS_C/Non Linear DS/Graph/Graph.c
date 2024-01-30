#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int numNodes;

void initializeGraph();
void addEdge(int, int, int);
void adjacencyMatrix(int);
void depthFirstSearch(int startNode);
void breadthFirstSearch(int startNode);
void dijkstra(int startNode);
void prim();

int main() {
    int choice;

    initializeGraph();

    do {
        printf("\nGraph Operations Menu:\n");
        printf("\n1. Depth-First Search");
        printf("\n2. Breadth-First Search");
        printf("\n3. Dijkstra's Algorithm");
        printf("\n4. Prim's Algorithm");
        printf("\n5. Krushkal's Algorithm");
        printf("\n6. Adjacency Matrix");
        printf("\n7. Exit");
    
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the starting node for DFS: ");
                int dfsStart;
                scanf("%d", &dfsStart);
                depthFirstSearch(dfsStart);
                break;

            case 2:
                printf("\nEnter the starting node for BFS: ");
                int bfsStart;
                scanf("%d", &bfsStart);
                breadthFirstSearch(bfsStart);
                break;

            case 3:
                printf("\nEnter the starting node for Dijkstra's Algorithm: ");
                int dijkstraStart;
                scanf("%d", &dijkstraStart);
                dijkstra(dijkstraStart);
                break;

            case 4:
                prim();
                break;

            case 5:
                prim();
                break;

            case 6:
                adjacencyMatrix(numNodes);
                break;
            
            case 7:
                printf("Exiting program. GoodBye!\n");
                break;

            default:
                printf("Invalid Choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}

void initializeGraph() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    //initialize
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges in the graph (from to weight, -1 to stop): \n");
    int from, to, weight;
    while(1) {
        scanf("%d %d %d", &from, &to, &weight);
        if(from == -1 || to == -1 || weight == -1) break;
        addEdge(from, to, weight);
    }
}

void addEdge(int from , int to, int weight) {
    graph[from][to] = weight;
    graph[to][from] = weight;   //for undirected graph (prim, krushkal)
}

void adjacencyMatrix(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

void depthFirstSearchUtil(int node, int visited[]) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < numNodes; i++) if(graph[node][i] != 0 && !visited[i]) depthFirstSearchUtil(i, visited);
}

void depthFirstSearch(int startNode) {
    int visited[MAX_NODES] = {0};

    printf("\nDepth-First Search starting from node %d: ", startNode);
    depthFirstSearchUtil(startNode, visited);
    printf("\n");
}

void breadthFirstSearch(int startNode) {
    int queue[MAX_NODES];
    int front = -1, rear = -1;
    int visited[MAX_NODES] = {0};

    printf("Breadth-First Search starting from node %d: ", startNode);

    visited[startNode] = 1;
    queue[++rear] = startNode;

    while(front != rear) {
        int currentNode = queue[++front];
        printf("%d ", currentNode);

        for(int i=0; i<numNodes; i++) {
            if(graph[currentNode][i] != 0 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");
}

void dijkstra(int startNode) {
    int distance[MAX_NODES];
    int visited[MAX_NODES] = {0};

    for (int i = 0; i < numNodes; i++) {
        distance[i] = INT_MAX;
    }
    
    distance[startNode] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        // Find the node with the minimum distance that has not been visited
        int u = -1;

        for (int i = 0; i < numNodes; i++) {
            if(!visited[i] && (u == -1 || distance[i] < distance[u])) u = i;
        }

        //Mark the selected node as visited
        visited[u] = 1;

        //Update the distance values of adjacent nodes
        for (int v = 0; v < numNodes; v++) {
            if(graph[u][v] != 0 && !visited[v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }        
    }

    //Print the shortest distances from the startNode
    printf("Shortest distance from node %d using Dijkstra's Algorithm: \n", startNode);
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }
}

void prim() {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    int mstSet[MAX_NODES] = {0};

    for (int i = 0; i < numNodes; i++) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numNodes; count++) {
        //Find the node with the min key value that is not yet in the MST
        int u = -1;
        for (int i = 0; i < numNodes; i++) {
            if(!mstSet[i] && (u == -1 || key[i] < key[u])) u=i;
        }
        

        //Mark the selected node as part of the MST set
        mstSet[u] = 1;

        //Update key values and parent for adjacent nodes in the MST set
        for (int v = 0; v < numNodes; v++) {
            if(graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    // Print the edges of the minimum spanning tree
    printf("Minimum Spanning Tree using Prim's Algorithm: \n");
    for(int i=1; i<numNodes; ++i) {
        printf("Edge: %d - %d, Weight: %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to perform union operation on two sets
void unionSets(int parent[], int i, int j) {
    int iParent = parent[i];
    int jParent = parent[j];

    // Update the parent of all nodes with parent[i] to parent[j]
    parent[i] = jParent;
    for (int k = 0; k < numNodes; ++k) {
        if (parent[k] == iParent) {
            parent[k] = jParent;
        }
    }
}

// Function to find the set to which a particular node belongs
int find(int parent[], int i) {
    return parent[i];
}

// Kruskal's algorithm for finding Minimum Spanning Tree
void kruskal() {
    int parent[MAX_NODES];
    int minEdge, u, v;

    // Initialize sets for each node
    for (int i = 0; i < numNodes; ++i) {
        parent[i] = i;
    }

    printf("Minimum Spanning Tree using Kruskal's Algorithm:\n");

    while (1) {
        minEdge = INT_MAX;
        u = -1;
        v = -1;

        // Iterate through all pairs of nodes to find the minimum edge
        for (int i = 0; i < numNodes; ++i) {
            for (int j = 0; j < numNodes; ++j) {
                // Check if the nodes i and j belong to different sets and there is an edge between them
                if (find(parent, i) != find(parent, j) && graph[i][j] != 0 && graph[i][j] < minEdge) {
                    minEdge = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // If no more edges to consider, exit the loop
        if (u == -1 || v == -1) {
            break;
        }

        // Perform union of sets represented by u and v
        unionSets(parent, u, v);

        // Print the selected edge and its weight
        printf("Edge: %d - %d, Weight: %d\n", u, v, minEdge);
    }
}


/*
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
3 4 1
-1 -1 -1

   0  1  2  3  4
0  0  2  4  0  0
1  0  0  1  7  0
2  0  0  0  3  0
3  0  0  0  0  1
4  0  0  0  0  0 

*/