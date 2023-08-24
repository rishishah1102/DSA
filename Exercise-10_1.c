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
typedef struct node
{
    int data;
    struct node *link;
} node1;
node1 *start = NULL, *new, *ptr;
void insert_begin()
{
    new = (node1 *)malloc(sizeof(node1));
    if (new == NULL)
    {
        printf("Value cannot be inserted\n");
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
            new->link = start;
        }
        else
        {
            new->link = start;
            ptr = start;
            while (ptr->link != start)
            {
                ptr = ptr->link;
            }
            start = new;
            ptr->link = start;
        }
    }
}
void insert_end()
{
    new = (node1 *)malloc(sizeof(node1));
    if (new == NULL)
    {
        printf("Value cannot be inserted\n");
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
            new->link = start;
        }
        else
        {
            ptr = start;
            while (ptr->link != start)
            {
                ptr = ptr->link;
            }
            ptr->link = new;
            new->link = start;
        }
    }
}
void insert_after_node_number()
{
    new = (node1 *)malloc(sizeof(node1));
    if (new == NULL)
    {
        printf("Value cannot be inserted\n");
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
            printf("Error!!The Link List is empty!!\n");
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
                ptr = ptr->link;
            } while (ptr != start);
            if (found == 1)
            {
                new->link = ptr->link;
                ptr->link = new;
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
        printf("Value cannot be inserted\n");
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
            printf("Error!!The link is empty!!\n");
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
                ptr = ptr->link;
            } while (ptr != start);
            if (found == 1)
            {
                if (ptr == start)
                {
                    new->link = ptr;
                    while (ptr->link != start)
                    {
                        ptr = ptr->link;
                    }
                    ptr->link = new;
                    start = new;
                }
                else
                {
                    new->link = ptr;
                    preptr->link = new;
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
        printf("Nothing to be deleted as ");
    }
    else if (start->link == start)
    {
        printf("The value deleted from List is %d\n", start->data);
        start = NULL;
    }
    else
    {
        ptr = start;
        while (ptr->link != start)
        {
            ptr = ptr->link;
        }
        printf("The value deleted from List is %d\n", start->data);
        start = start->link;
        ptr->link = start;
    }
    printf("\n");
}
void delete_end()
{
    if (start == NULL)
    {
        printf("Nothing to be deleted as ");
    }
    else if (start->link == start)
    {
        printf("The value deleted from List is %d\n", start->data);
        start = NULL;
    }
    else
    {
        node1 *preptr;
        ptr = start;
        while (ptr->link != start)
        {
            preptr = ptr;
            ptr = ptr->link;
        }
        printf("\nThe value deleted from the list is %d\n", ptr->data);
        preptr->link = start;
        free(ptr);
    }
    printf("\n");
}
void delete_after_node_number()
{
    if (start == NULL)
    {
        printf("Nothing to be deleted as the list is Empty\n");
    }
    else
    {
        node1 *preptr;
        ptr = start;
        int choice, found = 0, count = 0;
        printf("Enter the Number of Node after which you want to perform deletion : ");
        scanf("%d", &choice);
        if (start->link == start)
        {
            printf("There is no for deletion\n");
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
                    ptr = ptr->link;
                    break;
                }
                ptr = ptr->link;
            } while (ptr->link != start);
            if (found == 1)
            {
                printf("\nThe value deleted from the list is %d\n", ptr->data);
                preptr->link = ptr->link;
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
        printf("Nothing to be deleted as the list is Empty");
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
                ptr = ptr->link;
            } while (ptr != start);
            if (found == 1)
            {
                if (ptr == start)
                {
                    while (ptr->link != start)
                    {
                        ptr = ptr->link;
                    }
                    printf("\nThe value deleted from the list is %d\n", ptr->data);
                    start = start->link;
                    ptr->link = start;
                }
                else
                {
                    printf("\nThe value deleted from the list is %d\n", ptr->data);
                    preptr->link = ptr->link;
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
        printf("The Linked-List is EMPTY\n\n");
    }
    else
    {
        printf("------------------------------------------------------------------------------\n\n");
        ptr = start;
        do
        {
            printf("Value = %d\nLink = %d\nNode_Address = %d\n\n", ptr->data, ptr->link, ptr);
            ptr = ptr->link;
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