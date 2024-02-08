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
