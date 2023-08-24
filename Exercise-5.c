#include <stdio.h>
void enqueue(int);
void dequeue();
void search();
void traverse();
int Q[20];
int front = -1;
int rear = -1;
int N;
int main()
{
    int choice, val;
    printf("Enter the size of the queue : ");
    scanf("%d", &N);
    do
    {
        printf("Press 1-Enqueue 2-Dequeue 3-Searching 4-Traversing 5-Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("You choose ENQUEUE so which value you want to enqueue : ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            printf("You choose DEQUEUE \n");
            dequeue();
            break;

        case 3:
            printf("You choose SEARCH \n");
            search();
            break;

        case 4:
            printf("You choose TRAVERSE \n");
            traverse();
            break;

        default:
            break;
        }
    } while (choice != 5);
    return 0;
}
void enqueue(int value)
{
    if (rear >= N - 1)
    {
        printf("Queue Overflow\n");
    }
    else if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        Q[rear] = value;
        traverse();
    }
    else
    {
        rear++;
        Q[rear] = value;
        traverse();
    }
}
void dequeue()
{
    if (rear == -1 && front == -1 && front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The value deleted from queue is %d\n", Q[front]);
        if (rear == front)
        {
            rear = -1;
            front = -1;
        }
        front++;
        traverse();
    }
}
void search()
{
    int element, found = 0, m;
    printf("Enter the element you want to search : ");
    scanf("%d", &element);
    for (int i = rear; i > -1; i--)
    {
        if (element == Q[i])
        {
            found++;
            m = i;
            break;
        }
    }
    if (found == 1)
    {
        printf("The element you searched is at %d index and %d position\n", m, m + 1);
    }
    else
    {
        printf("No element found \n");
    }
}
void traverse()
{
    if (rear == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("Q[%d] = %d \n", i, Q[i]);
        }
    }
}