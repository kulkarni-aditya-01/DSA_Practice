#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of vertices

// Function prototypes
void DFS(int graph[MAX][MAX], int startVertex, int n);
void push(int stack[MAX], int* top, int vertex);
int pop(int stack[MAX], int* top);
int isEmpty(int top);

int main() {
    int graph[MAX][MAX] = {0}; // Adjacency matrix
    int n, startVertex;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the start vertex for DFS
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Perform DFS traversal
    printf("DFS Traversal starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex, n);

    return 0;
}

// Function to perform DFS using an adjacency matrix
void DFS(int graph[MAX][MAX], int startVertex, int n) {
    int visited[MAX] = {0};  // Array to keep track of visited vertices
    int stack[MAX];  // Stack for DFS
    int top = -1;     // Initialize stack pointer

    // Push the start vertex onto the stack
    push(stack, &top, startVertex);

    // While stack is not empty, continue DFS
    while (!isEmpty(top)) {
        int currentVertex = pop(stack, &top);
        
        // If the vertex is not visited
        if (visited[currentVertex] == 0) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;  // Mark the vertex as visited
        }

        // Push all unvisited adjacent vertices to the stack
        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && visited[i] == 0) {
                push(stack, &top, i);
            }
        }
    }
}

// Function to push a vertex onto the stack
void push(int stack[MAX], int* top, int vertex) {
    stack[++(*top)] = vertex;
}

// Function to pop a vertex from the stack
int pop(int stack[MAX], int* top) {
    return stack[(*top)--];
}

// Function to check if the stack is empty
int isEmpty(int top) {
    return top == -1;
}
