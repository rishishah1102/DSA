#include <stdio.h>
#define n 5
#define s 30
char queue[n][s];
int front = -1, rear = -1;
void display_cqueue();
void c_dequeue();
void c_enqueue();
int main()
{
    int c;
    do
    {
        printf("\nENTER YOUR CHOICE:");
        printf("1. ADD WEBPAGE \n2. SHOW PAGE \n3. Exit \n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            c_enqueue();
            break;

        case 2:
            display_cqueue();
            break;

        case 3:
            printf("\n  OOPS !! PROCESS ENDED ");
            return 0;
            break;

        default:
            printf("\nINCORRECT CHOICE\n");
            break;
        }
    } while (c != 3);
    return 0;
}
void c_enqueue()
{
    int p;
    char web[30];
    if (rear == n - 1)
    {
        c_dequeue();
    }
    else if (front == -1 && rear == -1)
    {
        printf("\nENTER WEBPAGE YOU WANT TO BE ADD:");
        scanf("%s", &web);
        front = rear = 0;
        for (int i = 0; i <= s; i++)
        {
            queue[rear][i] = web[i];
        }
    }
    else if (front > rear)
    {
        c_dequeue();
    }
    else
    {
        printf("\nENTER WEBPAGE YOU WANT TO BE ADD:");
        scanf("%s", &web);
        rear++;
        for (int i = 0; i <= s; i++)
        {
            queue[rear][i] = web[i];
        }
    }
    printf("\n DO YOU WANT TO CONTINUE:");
    printf("\n1.YES \n2.NO\n\n");
    printf("\nenter your choice:");
    scanf("%d", &p);
    if (p == 1)
    {
        c_enqueue();
    }
    else
    {
        main();
    }
}
void c_dequeue()
{
    if (front == n - 1)
    {
        front = 0;
    }
    front = front + 1;
}
void display_cqueue()
{
    printf("\nYOUR VISITED PAGES ARE\n\n");
    if (front > rear)
    {
        for (int i = n - 1; i >= front; i--)
        {
            printf("Queue[%d]: %s\n", i, queue[i]);
        }
        for (int i = rear; i >= 0; i--)
        {
            printf("Queue[%d]: %s\n", i, queue[i]);
        }
    }
    else
    {
        for (int i = rear; i >= front; i--)
        {
            printf("Queue[%d]: %s\n", i, queue[i]);
        }
    }
}