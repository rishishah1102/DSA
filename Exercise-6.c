#include <stdio.h>
#include <string.h>
#define size 3
void add_page();
void delete_page();
void display_page();
char historyofpages[size][20];
char webpage[20];
int front = -1;
int rear = -1;
int main()
{
    int choice;
    do
    {
        printf("\nSelect from below\n1-Add page of visit\n2-Display visited pages\n3-Exit\nChoice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Which page to add? : ");
            scanf("%s", webpage);
            getchar();
            add_page();
            break;

        case 2:
            display_page();
            break;

        default:
            break;
        }
    } while (choice < 3);
    return 0;
}
void add_page()
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        strcpy(historyofpages[rear], webpage);
        printf("The added page is %s \n", historyofpages[rear]);
    }
    else if (rear == size - 1)
    {
        delete_page();
        rear = 0;
        strcpy(historyofpages[rear], webpage);
        printf("The added page is %s \n", historyofpages[rear]);
    }
    else if (rear + 1 == front)
    {
        delete_page();
        rear++;
        strcpy(historyofpages[rear], webpage);
        printf("The added page is %s \n", historyofpages[rear]);
    }
    else
    {
        rear++;
        strcpy(historyofpages[rear], webpage);
        printf("The added page is %s \n", historyofpages[rear]);
    }
}
void delete_page()
{
    printf("The deleted page is %s \n", historyofpages[front]);
    front++;
    if (front == size)
    {
        front = 0;
    }
}
void display_page()
{
    printf("\nTHE PAGES YOU HAVE VISITED ARE\n");
    if (front == -1 && rear == -1)
    {
        printf("\nThere's nothing to show, EMPTY SET!");
    }
    else if (front > rear)
    {
        for (int i = rear; i >= 0; i--)
        {
            printf("%s\n", historyofpages[i]);
        }
        for (int i = size - 1; i >= front; i--)
        {
            printf("%s\n", historyofpages[i]);
        }
    }
    else if (front == rear) // single element
    {
        printf("%s\n", historyofpages[front]);
    }
    else
    {
        for (int i = rear; i >= front; i--)
        {
            printf("%s\n", historyofpages[i]);
        }
    }
}