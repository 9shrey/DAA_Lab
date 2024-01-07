#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int NumNodes;
  struct node** adjLists;
};

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = v;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct Graph* createAGraph(int NumNodes) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->NumNodes = NumNodes;

  graph->adjLists = malloc(NumNodes * sizeof(struct node*));

  int i;
  for (i = 0; i < NumNodes; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

void addEdge(struct Graph* graph, int node_from, int node_to) {
  
  struct node* newNode = createNode(node_to);
  newNode->next = graph->adjLists[node_from];
  graph->adjLists[node_from] = newNode;

  
  newNode = createNode(node_from);
  newNode->next = graph->adjLists[node_to];
  graph->adjLists[node_to] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->NumNodes; v++) {
    struct node* temp = graph->adjLists[v];
    printf("Value %d connected to: ", v);
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

void initArray(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}

int main() {
    
  struct Graph* graph = createAGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 2);

  printGraph(graph);

  return 0;
}