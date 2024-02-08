#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int vertex;
    struct ListNode *next;
};

struct Graph {
    int numVertices;
    struct ListNode **adjList;
};

struct ListNode *createNode(int vertex) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!node) {
        printf("Memory error!\n");
        return NULL;
    }

    node->vertex = vertex;
    node->next = NULL;
    return node;
}

struct Graph *createGraph(int numVertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    if (!graph) {
        printf("Memory error\n");
        return NULL;
    }

    graph->numVertices = numVertices;
    graph->adjList = (struct ListNode **)malloc(numVertices * sizeof(struct ListNode *));
    
    for (int i = 0; i < numVertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdgeList(struct Graph *graph, int src, int dest) {
    struct ListNode *node = createNode(dest);
    node->next = graph->adjList[src];
    graph->adjList[src] = node;
}

void printGraph(struct Graph *graph) {
    struct ListNode *temp;
    printf("The Adjacency List Representation: \n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        temp = graph->adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void initializematrix(int ***matrix, int numVertices) {
    *matrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        (*matrix)[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++)
            (*matrix)[i][j] = 0;
    }
}

void addEdge(int **matrix, int start, int end) {
    matrix[start][end] = 1;
}

void display(int **matrix, int numVertices) {
    printf("The Adjacency Matrix: \n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph *graph = createGraph(numVertices);

    int **matrix;
    initializematrix(&matrix, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    if (numEdges < 0 || numEdges > (numVertices * (numVertices - 1) / 2)) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter the edges (start, end)\n");
    int start, end;
    for (int i = 1; i <= numEdges; i++) {
        scanf("%d%d", &start, &end);
        if (start < 0 || start >= numVertices || end < 0 || end >= numVertices) {
            printf("The graph doesn't exist\n");
            return 1;
        }
        addEdge(matrix, start, end);
        addEdgeList(graph, start, end);
    }

    printGraph(graph);
    display(matrix, numVertices);

    // Free allocated memory
    for (int i = 0; i < numVertices; i++)
        free(matrix[i]);
    free(matrix);

    for (int i = 0; i < numVertices; i++) {
        struct ListNode *temp = graph->adjList[i];
        while (temp) {
            struct ListNode *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}


/* #include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform Breadth-First Search (BFS)
void BFS(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    int visited[MAX_VERTICES] = {0};  // Array to keep track of visited vertices
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Enqueue the starting vertex
    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    printf("BFS Traversal: ");

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (matrix[currentVertex][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Recursive function for Depth-First Search (DFS)
void DFSRecursive(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int currentVertex, int visited[MAX_VERTICES]) {
    printf("%d ", currentVertex);
    visited[currentVertex] = 1;

    for (int i = 0; i < numVertices; i++) {
        if (matrix[currentVertex][i] && !visited[i]) {
            DFSRecursive(matrix, numVertices, i, visited);
        }
    }
}

// Function to perform Depth-First Search (DFS)
void DFS(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    int visited[MAX_VERTICES] = {0};  // Array to keep track of visited vertices

    printf("DFS Traversal: ");
    DFSRecursive(matrix, numVertices, startVertex, visited);
    printf("\n");
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int matrix[MAX_VERTICES][MAX_VERTICES] = {0};  // Initialize the adjacency matrix with zeros

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (startVertex endVertex):\n");
    for (int i = 0; i < numEdges; i++) {
        int startVertex, endVertex;
        scanf("%d %d", &startVertex, &endVertex);
        matrix[startVertex][endVertex] = 1;
        matrix[endVertex][startVertex] = 1;  // Assuming an undirected graph
    }

    int startVertex;
    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    BFS(matrix, numVertices, startVertex);
    DFS(matrix, numVertices, startVertex);

    return 0;
}
 */