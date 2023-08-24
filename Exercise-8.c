#include <stdio.h>
#include <string.h>
void enqueue_front();
void enqueue_rear();
void dequeue_front();
void dequeue_rear();
void get_front();
void get_rear();
int isfull();
int isempty();
void traverse();
int Q[20];
int front = -1;
int rear = -1;
int N;
int main()
{
    printf("Enter the size of the doubly ended Queue : ");
    scanf("%d", &N);
    int choice;
    do
    {
        printf("\nPress 1-Enqueue_Front 2-Dequeue_Front 3-Enqueue_Rear 4-Dequeue_Rear 5-Get_Front 6-Get_Rear 7-Traversing 8-Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nYou choose ENQUEUE_Front \n");
            enqueue_front();
            break;

        case 2:
            printf("\nYou choose DEQUEUE_Front \n");
            dequeue_front();
            break;

        case 3:
            printf("\nYou choose ENQUEUE_Rear \n");
            enqueue_rear();
            break;

        case 4:  
            printf("\nYou choose DEQUEUE_Rear \n");
            dequeue_rear();
            break;

        case 5: 
            printf("You choose Get_Front \n");
            get_front();
            break;

        case 6: 
            printf("You choose Get_Rear \n");
            get_rear();
            break;

        case 7:
            printf("\nYou choose TRAVERSE \n");
            traverse();
            break;

        default:
            break;
        }
    } while (choice != 8);
    return 0;
}
int isfull()
{
    if ((rear == N-1 && front == 0) || (rear+1 == front) || (front-1 == rear))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void get_front()
{
    if (isempty())
    {
        printf("Queue Underflow \n");
    }
    else
    {
        printf("Q[%d] = %d \n", front, Q[front]);
    }
}
void get_rear()
{
    if (isempty())
    {
        printf("Queue Underflow \n");
    }
    else
    {
        printf("Q[%d] = %d \n", rear, Q[rear]);
    }
}
void enqueue_front()
{
    int value;
    printf("Enter the value to be enqueued : ");
    scanf("%d", &value);
    if (isfull())
    {
        printf("Queue Overflow \n");
    }
    else if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        Q[front] = value;
        printf("The value inserted in the queue is %d \n", Q[front]);
    }
    else if (front == 0 && rear != N - 1)
    {
        front = N-1;
        Q[front] = value;
        printf("The value inserted in the queue is %d \n", Q[front]);
    }
    else
    {
        front--;
        Q[front] = value;
        printf("The value inserted in the queue is %d \n", Q[front]);
    }
}
void dequeue_front()
{
    if (isempty())
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
void enqueue_rear()
{
    int value;
    printf("Enter the value to be enqueued : ");
    scanf("%d", &value);
    if (isfull())
    {
        printf("Queue Overflow \n");
    }
    else if (rear == -1 && front == -1)
    {
        rear++;
        front++;
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
void dequeue_rear()
{
    if (isempty())
    {
        printf("Queue Underflow \n");
    }
    else if (front != -1 && rear != -1 && front == rear)
    {
        printf("The deleted item from Queue is %d \n", Q[rear]);
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        printf("The deleted item from Queue is %d \n", Q[rear]);
        rear = N-1;
    }
    else
    {
        printf("The deleted item from Queue is %d \n", Q[rear]);
        rear--;
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