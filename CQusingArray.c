#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Define the structure of the circular queue
struct CircularQueue {
    int front, rear;
    int items[MAX_SIZE];
};

// Function to create an empty circular queue
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* newQueue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    return ((queue->rear+1) % MAX_SIZE == queue->front);
}

// Function to add an element to the rear of the circular queue
void enqueue(struct CircularQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Circular queue is full.\n");
    } else if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
        queue->items[queue->rear] = data;
    } else {
        queue->rear = (queue->rear+1) % MAX_SIZE;
        queue->items[queue->rear] = data;
    }
}

// Function to remove an element from the front of the circular queue
int dequeue(struct CircularQueue* queue) {
    int deletedData = -1;
    if (isEmpty(queue)) {
        printf("Circular queue is empty.\n");
    } else if (queue->front == queue->rear) {
        deletedData = queue->items[queue->front];
        queue->front = queue->rear = -1;
    } else {
        deletedData = queue->items[queue->front];
        queue->front = (queue->front+1) % MAX_SIZE;
    }
    return deletedData;
}

// Function to display the elements in the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty.\n");
    } else {
        printf("Elements in the circular queue are: ");
        int i;
        for (i = queue->front; i != queue->rear; i = (i+1) % MAX_SIZE) {
            printf("%d ", queue->items[i]);
        }
        printf("%d\n", queue->items[i]);
    }
}

// Main function
int main() {
    struct CircularQueue* queue = createCircularQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    printf("Deleted element: %d\n", dequeue(queue));
    printf("Deleted element: %d\n", dequeue(queue));
    display(queue);
    enqueue(queue, 40);
    enqueue(queue, 50);
    display(queue);
    printf("Deleted element: %d\n", dequeue(queue));
    display(queue);
    return 0;
}
