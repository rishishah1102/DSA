#include <stdio.h>
int stack[20];
int top = -1;
int size;
void push();
void pop();
void peek();
void peep();
void change();
void traverse();
int main()
{
    int choice, val, search;
    printf("Enter the size of stack : ");
    scanf("%d", &size);
    printf("\n");
    do
    {
        printf("Choose the operation to perform\n");
        printf("1-Push , 2-Pop , 3-Peek , 4-Peep , 5-Change , 6-Traverse , 7-exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("You choose push so which value you want to push in stack : ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            printf("You selected peep so which element you want to peep : ");
            scanf("%d", &search);
            peep(search);
            break;

        case 5:
            change();
            break;

        case 6:
            traverse();
            break;

        default:
            break;
        }
    } while (choice != 7);
    return 0;
}
void push(int e)
{
    if (top == size - 1)
    {
        printf("Stack Overflow \n");
    }
    else
    {
        top = top + 1;
        stack[top] = e;
        printf("The element pushed is %d \n", stack[top]);
        traverse();
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        printf("The deleted item from stack is %d \n", stack[top]);
        top = top - 1;
        traverse();
    }
}
void peek()
{
    if (top == -1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        printf("The value peeked is %d \n", stack[top]);
        printf("\n");
    }
}
void peep(int find)
{
    if (top == -1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        int found = 0, e;
        for (int i = top; i > -1; i--)
        {
            if (stack[i] == find)
            {
                found += 1;
                e = i;
            }
        }
        if (found == 1)
        {

            printf("The element you searched is at %d index \n", e);
            printf("\n");
        }
        else
        {
            printf("No element found with that input \n");
            printf("\n");
        }
    }
}
void change()
{
    int changee, pos;
    printf("Enter the value which you want to change : ");
    scanf("%d", &changee);
    printf("Enter the position in which you want to change the element of stack : ");
    scanf("%d", &pos);
    if (top == -1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        if (pos-1 > top)
        {
            printf("There is no element to be changed\n");
        }
        else
        {
            stack[pos - 1] = changee;
        }
    }
    traverse();
}
void traverse()
{
    if (top == -1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        for (int i = top; i > -1; i--)
        {
            printf("stack[%d]=%d\n", i, stack[i]);
        }
    }
    printf("\n");
}
