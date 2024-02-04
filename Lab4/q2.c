#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Graph {
    int V;
    struct Node** array;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; ++i)
        graph->array[i] = NULL;
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* node = newNode(dest);
    node->next = graph->array[src];
    graph->array[src] = node;
    node = newNode(src);
    node->next = graph->array[dest];
    graph->array[dest] = node;
}
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
    printf("Pushed %d\n", item);
}
int pop(struct Stack* stack) {
    int item = stack->array[stack->top--];
    printf("Popped %d\n", item);
    return item;
}
void DFSUtil(struct Graph* graph, int v, int visited[], struct Stack* stack) {
    visited[v] = 1;
    push(stack, v);
    struct Node* node = graph->array[v];
    while (node != NULL) {
        if (!visited[node->data])
            DFSUtil(graph, node->data, visited, stack);
        node = node->next;
    }
    pop(stack);
}
void DFS(struct Graph* graph) {
    struct Stack* stack = createStack(graph->V);
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;
    for (int i = 0; i < graph->V; i++)
        if (visited[i] == 0)
            DFSUtil(graph, i, visited, stack);
    free(stack->array);
    free(stack);
    free(visited);
}
int main() {
    int V = 7;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    printf("\nPush and pop order in DFS traversal:\n");
    DFS(graph);
    return 0;
}
