#include <stdio.h>
#include <stdlib.h>
void enqueue();
void dequeue();
void traversal();
typedef struct node
{
    int data;
    struct node *link;
} queue;
queue *front = NULL, *new, *rear = NULL;
void enqueue()
{
    new = (queue *)malloc(sizeof(queue));
    if (new == NULL)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        int value;
        printf("Enter the value to be inserted : ");
        scanf("%d", &value);
        new->data = value;
        if (front == NULL)
        {
            front = new;
            rear = new;
            new->link = NULL;
        }
        else
        {
            rear->link = new;
            rear = rear->link;
            new->link = NULL;
        }
    }
}
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The element deleted from Queue is %d\n", front->data);
        front = front->link;
    }
}
void traversal()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        queue *ptr;
        ptr = front;
        printf("------------------------------------------------------------------------------\n\n");
        while (ptr != NULL)
        {
            printf("Data - %d\n", ptr->data);
            ptr = ptr->link;
        }
        printf("\n------------------------------------------------------------------------------\n\n");
    }
}
int main()
{
    int choice;
    do
    {
        printf("Press 1-Enqueue 2-Dequeue 3-Traversal 4-Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            traversal();
            break;

        default:
            break;
        }
    } while (choice < 4);

    return 0;
}
