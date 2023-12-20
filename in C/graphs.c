#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjacencyList[MAX_VERTICES];
};

struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void displayAdjacencyList(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("Adjacency List of vertex %d: ", i);
        struct Node* temp = graph->adjacencyList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void displayAdjacencyMatrix(struct Graph* graph) {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* temp = graph->adjacencyList[i];
        while (temp != NULL) {
            adjacencyMatrix[i][temp->data] = 1;
            temp = temp->next;
        }
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjacencyList[vertex];
    while (temp != NULL) {
        if (!visited[temp->data])
            DFSUtil(graph, temp->data, visited);
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    printf("Depth First Search starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue* queue, int item) {
    queue->array[++queue->rear] = item;
    if (queue->front == -1)
        ++queue->front;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        ++queue->front;
    return item;
}

void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    struct Queue* queue = createQueue(MAX_VERTICES);

    printf("Breadth First Search starting from vertex %d: ", startVertex);
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjacencyList[currentVertex];
        while (temp != NULL) {
            int adjacentVertex = temp->data;
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = 1;
                enqueue(queue, adjacentVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nGraph Operations:\n");
    printf("1. Compute adjacency list and adjacency matrix\n");
    printf("2. Perform a depth-first search\n");
    printf("3. Perform a breadth-first search\n");
    printf("4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAdjacencyList(graph);
                displayAdjacencyMatrix(graph);
                break;
            case 2:
                printf("Enter the starting vertex for depth-first search: ");
                int startDFS;
                scanf("%d", &startDFS);
                DFS(graph, startDFS);
                break;
            case 3:
                printf("Enter the starting vertex for breadth-first search: ");
                int startBFS;
                scanf("%d", &startBFS);
                BFS(graph, startBFS);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}