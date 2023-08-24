#include <stdio.h>
void stack1();
void stack2();
void traverse1();
void traverse2();
int stack[30];
int top1 = -1;
int top2 = 30;
int main()
{
    int s1;
    printf("Enter the size of 1st Stack : ");
    scanf("%d", &s1);
    int s2 = 30 - s1;
    int choice;
    do
    {
        printf("Choose 1-1st Stack and 2-2nd Stack and 3-Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            stack1(s1);
            break;

        case 2:
            stack2(s1, s2);
            break;

        default:
            break;
        }
    } while (choice != 3);
    return 0;
}
void stack1(int size1)
{
    int choice;
    do
    {
        printf("Choose 1-Push 2-Pop 3-Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("You choose PUSH\n");
            int element;
            printf("Enter the value to be pushed : ");
            scanf("%d", &element);
            if (top1 == size1 - 1)
            {
                printf("Stack Overflow \n");
            }
            else
            {
                top1 = top1 + 1;
                stack[top1] = element;
                printf("The element pushed is %d \n", stack[top1]);
                traverse1();
            }
            break;

        case 2:
            printf("You choose POP\n");
            if (top1 == -1)
            {
                printf("Stack underflow \n");
            }
            else
            {
                printf("The deleted item from stack is %d \n", stack[top1]);
                top1 = top1 - 1;
                traverse1();
            }
            break;

        default:
            break;
        }
    } while (choice != 3);
}
void traverse1()
{
    if (top1 == -1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        for (int i = top1; i > -1; i--)
        {
            printf("stack[%d]=%d \n", i, stack[i]);
        }
    }
    printf("\n");
}
void stack2(int size1, int size2)
{
    int choice;
    do
    {
        printf("Choose 1-Push 2-Pop 3-Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("You choose PUSH\n");
            int element;
            printf("Enter the value to be pushed : ");
            scanf("%d", &element);
            if (top2 == size1)
            {
                printf("Stack Overflow \n");
            }
            else
            {
                top2 = top2 - 1;
                stack[top2] = element;
                printf("The element pushed is %d \n", stack[top2]);
                traverse2();
            }
            break;

        case 2:
            printf("You choose POP\n");
            if (top2 == 30)
            {
                printf("Stack underflow \n");
            }
            else
            {
                printf("The deleted item from stack is %d \n", stack[top2]);
                top2 = top2 + 1;
                traverse2();
            }
            break;

        default:
            break;
        }
    } while (choice != 3);
}
void traverse2()
{
    if (top2 == 30)
    {
        printf("Stack Underflow");
    }
    else
    {
        for (int i = top2; i < 30; i++)
        {
            printf("stack[%d] = %d \n", i, stack[i]);
        }
    }
    printf("\n");
}