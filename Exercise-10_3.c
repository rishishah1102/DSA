#include <stdio.h>
#include <stdlib.h>
void insert_begin();
void insert_end();
void insert_after_node_number();
void insert_before_node_number();
void delete_begin();
void delete_end();
void delete_after_node_number();
void delete_before_node_number();
void display();
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node node1;
node1 *start = NULL;
node1 *new, *ptr;
void insert_begin()
{
    new = (node1 *)malloc(sizeof(node1));
    if (new == NULL)
    {
        printf("List Overflow");
    }
    else
    {
        int value;
        printf("Enter the value to be inserted : ");
        scanf("%d", &value);
        new->data = value;
        if (start == NULL)
        {
            start = new;
            new->next = start;
            new->prev = start;
            printf("The value inserted is %d\n\n", new->data);
        }
        else
        {
            new->next = start;
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            start->prev = new;
            new->prev = ptr;
            start = new;
            ptr->next = start;
            printf("The value inserted is %d\n\n", new->data);
        }
    }
}
void insert_end()
{
    new = (node1 *)malloc(sizeof(node1));
    if (new == NULL)
    {
        printf("List Overflow\n");
    }
    else
    {
        int value;
        printf("Enter the value to be inserted : ");
        scanf("%d", &value);
        printf("\n");
        new->data = value;
        if (start == NULL)
        {
            start = new;
            new->next = start;
            new->prev = start;
            printf("The value inserted is %d\n\n", new->data);
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            new->next = ptr->next;
            ptr->next = new;
            new->prev = ptr;
            start->prev = new;
            printf("The value inserted is %d\n\n", new->data);
        }
    }
}
void insert_after_node_number()
{
    new = (node1 *)malloc(sizeof(node1));
    if (new == NULL)
    {
        printf("List Overflow\n");
    }
    else
    {
        int value;
        printf("Enter the value to be inserted : ");
        scanf("%d", &value);
        printf("\n");
        new->data = value;
        if (start == NULL)
        {
            printf("List Underflow!!\n");
        }
        else
        {
            ptr = start;
            int choice, count = 0, found = 0;
            printf("Enter the NODE after which you want to perform insertion : ");
            scanf("%d", &choice);
            do
            {
                count++;
                if (count == choice)
                {
                    found += 1;
                    break;
                }
                ptr = ptr->next;
            } while (ptr != start);
            if (found == 1)
            {
                if (ptr->next == start)
                {
                    new->prev = ptr;
                    new->next = ptr->next;
                    ptr->next = new;
                    start->prev = new;
                    printf("The value inserted is %d\n\n", new->data);
                }
                else
                {
                    new->prev = ptr;
                    new->next = ptr->next;
                    ptr->next->prev = new;
                    ptr->next = new;
                    printf("The value inserted is %d\n\n", new->data);
                }
            }
            else
            {
                printf("There is no Node of your choice after which you can perform insertion\n");
            }
        }
    }
}
void insert_before_node_number()
{
    new = (node1 *)malloc(sizeof(node1));
    if (new == NULL)
    {
        printf("List Overflow\n");
    }
    else
    {
        int value;
        printf("Enter the value to be inserted : ");
        scanf("%d", &value);
        printf("\n");
        new->data = value;
        if (start == NULL)
        {
            printf("List Underflow!!\n");
        }
        else
        {
            node1 *preptr;
            ptr = start;
            int choice, count = 0, found = 0;
            printf("Enter the NODE before which you want to perform insertion : ");
            scanf("%d", &choice);
            do
            {
                count++;
                if (count == choice)
                {
                    found += 1;
                    break;
                }
                preptr = ptr;
                ptr = ptr->next;
            } while (ptr != start);
            if (found == 1)
            {
                if (ptr == start)
                {
                    new->next = start;
                    ptr = start;
                    while (ptr->next != start)
                    {
                        ptr = ptr->next;
                    }
                    start->prev = new;
                    new->prev = ptr;
                    start = new;
                    ptr->next = start;
                    printf("The value inserted is %d\n\n", new->data);
                }
                else
                {
                    new->prev = preptr;
                    new->next = ptr;
                    preptr->next = new;
                    ptr->prev = new;
                    printf("The value inserted is %d\n\n", new->data);
                }
            }
            else
            {
                printf("There is no Node of your choice before which you can perform insertion\n");
            }
        }
    }
}
void delete_begin()
{
    if (start == NULL)
    {
        printf("List Underflow\n");
    }
    else if (start->next == start)
    {
        printf("The deleted element is %d\n\n", start->data);
        start = NULL;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        printf("The value deleted from List is %d\n", start->data);
        start = start->next;
        start->prev = ptr;
        ptr->next = start;
    }
    printf("\n");
}
void delete_end()
{
    if (start == NULL)
    {
        printf("List Underflow\n");
    }
    else if (start->next == NULL)
    {
        printf("The deleted element is %d\n\n", start->data);
        start = NULL;
    }
    else
    {
        node1 *preptr;
        ptr = start;
        while (ptr->next != start)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        printf("The deleted element is %d\n\n", ptr->data);
        preptr->next = start;
        start->prev = preptr;
        free(ptr);
    }
    printf("\n");
}
void delete_after_node_number()
{
    if (start == NULL)
    {
        printf("List Underflow\n");
    }
    else
    {
        node1 *preptr;
        ptr = start;
        int choice, found = 0, count = 0;
        printf("Enter the Number of Node after which you want to perform deletion : ");
        scanf("%d", &choice);
        if (start->next == NULL)
        {
            printf("There is no element after which we can perform deletion\n");
        }
        else
        {
            do
            {
                count++;
                preptr = ptr;
                if (count == choice)
                {
                    found += 1;
                    ptr = ptr->next;
                    break;
                }
                ptr = ptr->next;
            } while (ptr != start);
            if (found == 1)
            {
                printf("The deleted element is %d\n\n", ptr->data);
                ptr->next->prev = preptr;
                preptr->next = ptr->next;
            }
            else
            {
                printf("There is no element after which we can perform deletion\n");
            }
            free(ptr);
        }
    }
    printf("\n");
}
void delete_before_node_number()
{
    if (start == NULL)
    {
        printf("List Underflow\n");
    }
    else
    {
        node1 *preptr = NULL;
        ptr = start;
        int choice, found = 0, count = 1;
        // Here we have to make count = 1 because than only ptr will point on before node
        printf("Enter the Number of Node before which you want to perform deletion : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("There is no element before which we can perform deletion\n");
        }
        else
        {
            do
            {
                count++;
                if (count == choice)
                {
                    found += 1;
                    break;
                }
                preptr = ptr;
                ptr = ptr->next;
            } while (ptr != start);
            if (found == 1)
            {
                if (ptr == start)
                {
                    ptr = start;
                    while (ptr->next != start)
                    {
                        ptr = ptr->next;
                    }
                    printf("The value deleted from List is %d\n", start->data);
                    start = start->next;
                    start->prev = ptr;
                    ptr->next = start;
                }
                else
                {
                    printf("The deleted element is %d\n\n", ptr->data);
                    preptr->next = ptr->next;
                    ptr->next->prev = preptr;
                }
            }
            else
            {
                printf("There is no  element before which we can perform deletion\n");
            }
            free(ptr);
        }
    }
    printf("\n");
}
void display()
{
    if (start == NULL)
    {
        printf("List Underflow\n");
    }
    else
    {
        ptr = start;
        printf("------------------------------------------------------------------------------\n\n");
        do
        {
            printf("Data = %d\nPrevious = %d\nNext = %d\nNode = %d\n\n", ptr->data, ptr->prev, ptr->next, ptr);
            ptr = ptr->next;
        } while (ptr != start);
        printf("------------------------------------------------------------------------------\n");
    }
}
int main()
{
    int choice;
    do
    {
        printf("Press\n1-Insert_Begin\n2-Insert_End\n3-Insert_after_node_number\n4-Insert_before_node_number\n5-Delete_Begin\n6-Delete_End\n7-Delete_after_node_number\n8-Delete_before_node_number\n9-Display\n10-Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_begin();
            break;

        case 2:
            insert_end();
            break;

        case 3:
            insert_after_node_number();
            break;

        case 4:
            insert_before_node_number();
            break;

        case 5:
            delete_begin();
            break;

        case 6:
            delete_end();
            break;

        case 7:
            delete_after_node_number();
            break;
        case 8:
            delete_before_node_number();
            break;

        case 9:
            display();
            break;

        default:
            break;
        }
    } while (choice < 10);
    return 0;
}