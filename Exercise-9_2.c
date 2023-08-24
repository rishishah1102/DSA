#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
typedef struct node
{
    int data;
    struct node *link;
} stack;
stack *start = NULL, *new, *ptr = NULL;
void push()
{
    new = (stack *)malloc(sizeof(stack));
    if (new == NULL)
    {
        printf("No more Memory available to push the element\n");
    }
    else
    {
        int value;
        printf("Entered the value to be pushed : ");
        scanf("%d", &value);
        new->data = value;
        if (start == NULL)
        {
            start = new;
            new->link = NULL;
        }
        else
        {
            new->link = start;
            start = new;
        }
    }
}
void pop()
{
    if (start == NULL)
    {
        printf("STACK Underflow\n");
    }
    else
    {
        ptr = start;
        printf("The value deleted from the stack is %d\n", ptr->data);
        start = ptr->link;
        free(ptr);
    }
}
void display()
{
    if (start == NULL)
    {
        printf("The stack is empty\n");
    }
    else
    {
        ptr = start;
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
        printf("Press 1-Push 2-Pop 3-Display and 4-Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    } while (choice < 4);
    return 0;
}