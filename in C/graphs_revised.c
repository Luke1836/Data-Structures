#include <stdio.h>
#include <stdlib.h>

void initializematrix(int matrix[][100], int numVertices)
{
    for(int i = 0 ; i < numVertices ; i++)
        for(int j = 0 ; j < numVertices ; j++)
            matrix[i][j] = 0;
}

void addEdge(int matrix[][100], int start, int end)
{
    matrix[start][end] = 1;
}

void display(int matrix[][100], int numVertices)
{
    printf("THe Adjacency Matrix: \n");
    for(int i = 0 ; i < numVertices ; i++)
    {  for(int j = 0 ; j < numVertices ; j++)
        printf("%d\t", matrix[i][j]);
       printf("\n");
    }
    printf("\n");
}

int main(void)
{
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    int matrix[numVertices][numVertices];
    initializematrix(matrix, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    if(numEdges < 0 || numEdges > (numVertices * (numVertices - 1) / 2))
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter the edges (start, end)\n");
    int start, end;
    for(int i = 1 ; i <= numEdges ; i++)
    {
        scanf("%d%d", &start, &end);
        if(start < 0 || start >= numVertices || end < 0 || end >= numVertices)
        {
            printf("The graph doesn't exists\n");
            return 1;
        }
        addEdge(matrix, start, end);
    }

    display(matrix, numVertices);
    return 0;
}