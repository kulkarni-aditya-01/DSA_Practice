#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum size of each queue
#define NUM_QUEUES 3  // Number of queues

// Define the queue structure
struct queue {
    int data[MAX];
    int front;
    int rear;
};

// Function prototypes
void enqueue(struct queue *q, int value);
int dequeue(struct queue *q);
int isEmpty(struct queue *q);
int isFull(struct queue *q);
void display(struct queue *q);

int main() {
    struct queue queue[NUM_QUEUES];  // Array of 3 queues

    // Initialize all queues
    for (int i = 0; i < NUM_QUEUES; i++) {
        queue[i].front = -1;
        queue[i].rear = -1;
    }

    // Sample usage
    printf("Enqueue into Queue 0:\n");
    enqueue(&queue[0], 10);
    enqueue(&queue[0], 20);
    display(&queue[0]);

    printf("\nEnqueue into Queue 1:\n");
    enqueue(&queue[1], 100);
    enqueue(&queue[1], 200);
    display(&queue[1]);

    printf("\nDequeue from Queue 0:\n");
    printf("Dequeued: %d\n", dequeue(&queue[0]));
    display(&queue[0]);

    printf("\nEnqueue into Queue 2:\n");
    enqueue(&queue[2], 500);
    enqueue(&queue[2], 600);
    display(&queue[2]);

    return 0;
}

// Enqueue function
void enqueue(struct queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0;  // Initialize front on the first enqueue
    }
    q->data[++q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue function
int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;  // Return an error value
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        // Reset queue when it becomes empty
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Check if the queue is empty
int isEmpty(struct queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(struct queue *q) {
    return q->rear == MAX - 1;
}

// Display the queue
void display(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
