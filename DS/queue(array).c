#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int front=-1,rear=-1;

void enqueue(int element)
{
    if(rear==size-1)
        printf("queue is full\n");
    else
    {
        if(front==-1)
            front=0;
        rear=rear+1;
        queue[rear]= element;
        printf("inserted\n");
    }
}

void dequeue()
{
    if(front==-1||front>rear)
        printf("queue is empty\n");
    else
    {
        front = front+1;
    }
}

void display()
{
    int i;
    if(front==-1||front>rear)
        printf("queue is empty\n");
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d",queue[i]);
            printf("\n");
        }
    }
}
int main() {
    int choice, value;
    
    while(1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                printf("Queue elements:\n");
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
