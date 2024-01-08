#include<stdio.h>
#include<stdlib.h>
#define V 4

typedef struct Node{
	int vertex;
	struct Node* next;
}Node;

typedef struct Graph{
	int numVertices;
	struct Node** adjVertices;
}Graph;

struct Node* createNode(int vertex){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->vertex = vertex;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int vertices){
	struct Graph* graph = malloc(sizeof(Graph));
	graph->numVertices = vertices;
	graph->adjVertices = malloc(vertices * sizeof(struct Node*));
	for(int i=0;i<vertices;i++){
		graph->adjVertices[i]=NULL;
	}
	return graph;
}

void addEdges(struct Graph* graph, int vertex1, int vertex2){
	struct Node* newNode = createNode(vertex2);
	newNode->next = graph->adjVertices[vertex1];
	graph->adjVertices[vertex1] = newNode;

	newNode = createNode(vertex1);
	newNode->next = graph->adjVertices[vertex2];
	graph->adjVertices[vertex2] = newNode;
}

void printAdjList(struct Graph* graph){
	int v;
  	for (v = 0; v < graph->numVertices; v++) {
	    struct Node* temp = graph->adjVertices[v];
	    printf("\n Vertex %d\n: ", v);
	    while (temp) {
	      	printf("%d -> ", temp->vertex);
	     	temp = temp->next;
    	}
    printf("\n");
  	}
}

void init(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}

void addEdgeMat(int arr[][V], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}

void printAdjMatrix(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
	int adjMatrix[V][V];
  	init(adjMatrix);
  
	struct Graph* graph = createGraph(4);
	addEdges(graph, 0, 1);
	addEdgeMat(adjMatrix, 0, 1);
	addEdges(graph, 0, 2);
	addEdgeMat(adjMatrix, 0, 2);
	addEdges(graph, 0, 3);
	addEdgeMat(adjMatrix, 0, 3);
	addEdges(graph, 1, 2);
	addEdgeMat(adjMatrix, 1, 2);

	printAdjList(graph);
	printf("\n");  
	printAdjMatrix(adjMatrix);


	return 0;
}