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
        printf("\n5. Adjacency Matrix");
        printf("\n6. Exit");
    
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
                // dijkstra(dijkstraStart);
                break;

            case 4:
                // prim();
                break;

            case 5:
                adjacencyMatrix(numNodes);
                break;
            
            case 6:
                printf("Exiting program. GoodBye!\n");
                break;

            default:
                printf("Invalid Choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

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
    // graph[to][from] = weight;   //for undirected graph
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