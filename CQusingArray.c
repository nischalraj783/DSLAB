#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int front, rear;
    int items[MAX_SIZE];
};

struct CircularQueue* createCircularQueue() {
    struct CircularQueue* newQueue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct CircularQueue* queue) {
    return ((queue->rear+1) % MAX_SIZE == queue->front);
}

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

int main() {
    struct CircularQueue* queue = createCircularQueue();
    int choice, data;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Deleted element: %d\n", data);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
