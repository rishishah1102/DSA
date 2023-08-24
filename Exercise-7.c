#include <stdio.h>
void enqueue(int);
void dequeue();
void search();
void traverse();
int Q[10];
int front = -1;
int rear = -1;
int N;
int main()
{
    int choice, val;
    printf("Enter the size of the Circular queue : ");
    scanf("%d", &N);
    do
    {
        printf("\nPress 1-Enqueue 2-Dequeue 3-Traversing 4-Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nYou choose ENQUEUE so which value you want to enqueue : ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            printf("\nYou choose DEQUEUE \n");
            dequeue();
            break;

        case 3:
            printf("\nYou choose TRAVERSE \n");
            traverse();
            break;

        default:
            break;
        }
    } while (choice != 4);
    return 0;
}
void enqueue(int value)
{
    if ((front == 0 && rear == N - 1) || (rear + 1 == front))
    {
        printf("Queue Overflow \n");
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        Q[rear] = value;
        printf("The value inserted in the queue is %d \n", Q[rear]);
    }
    else if (front != 0 && rear == N - 1)
    {
        rear = 0;
        Q[rear] = value;
        printf("The value inserted in the queue is %d \n", Q[rear]);
    }
    else
    {
        rear++;
        Q[rear] = value;
        printf("The value inserted in the queue is %d \n", Q[rear]);
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow \n");
    }
    else if (front != -1 && rear != -1 && front == rear)
    {
        printf("The deleted item from Queue is %d \n", Q[front]);
        front = -1;
        rear = -1;
    }
    else if (front == N - 1)
    {
        printf("The deleted item from Queue is %d \n", Q[front]);
        front = 0;
    }
    else
    {
        printf("The deleted item from Queue is %d \n", Q[front]);
        front++;
    }
}
void traverse()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow \n");
    }
    if (front == 0 && rear == 0)
    {
        printf("Q[%d] = %d \n", rear, Q[rear]);
    }
    if (front < rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("Q[%d] = %d \n", i, Q[i]);
        }
    }
    if (front > rear)
    {
        for (int i = front; i <= N-1; i++)
        {
            printf("Q[%d] = %d \n", i, Q[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("Q[%d] = %d \n", i, Q[i]);
        }   
    }
}
