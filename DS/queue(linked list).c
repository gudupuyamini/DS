#include <stdio.h>
#include <stdlib.h>
typedef struct queue {
    int data;
    struct queue *next;
} Queue;
Queue *front = NULL;
Queue *rear = NULL;
int count = 0;

void enqueue(int info) {
    Queue *newnode = (Queue*)malloc(sizeof(Queue));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = info;
    newnode->next = NULL;
    
    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    count++;
    printf("Enqueued: %d\n", info);
}
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Queue *temp = front;
    int x = temp->data;
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
    count--;
    printf("Dequeued: %d\n", x);
    return x;
}

void display() {
    Queue *temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements (%d items): ", count);
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, value;
    printf("Queue using Linked List\n");
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
