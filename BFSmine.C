#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_SIZE 100
int i,j;
// Queue structure for BFS
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to add an item to the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
	printf("Queue is full\n");
    } else {
	if (q->front == -1) {
	    q->front = 0;
	}
	q->rear++;
	q->items[q->rear] = value;
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
	printf("Queue is empty\n");
	item = -1;
    } else {
	item = q->items[q->front];
	q->front++;
	if (q->front > q->rear) {
	    q->front = q->rear = -1;
	}
    }
    return item;
}

// Function to perform BFS on a graph represented by an adjacency matrix
void bfs(int graph[MAX_SIZE][MAX_SIZE], int vertices, int startVertex) {
    struct Queue* q = createQueue();
    int visited[MAX_SIZE] = {0};

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);
    printf("%d ", startVertex);
    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
	int currentVertex = dequeue(q);

	for (i = 0;i < vertices; i++)
	 {
	    if (graph[currentVertex][i] == 1 && !visited[i])
	    {
		printf("%d ", i);
		visited[i] = 1;
		enqueue(q, i);
	    }
	}
    }

    printf("\n");
}

int main() {
    int vertices, startVertex;
    int graph[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);



    printf("Enter the adjacency matrix:\n");
    for (i=0;i<vertices;i++)
    {
	for ( j = 0; j < vertices; j++)
	{
	    scanf("%d", &graph[i][j]);
	}
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    bfs(graph, vertices, startVertex);

    getch();
}
