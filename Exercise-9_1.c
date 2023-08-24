#include <stdio.h>
#include <stdlib.h>
void insert_begin();
void insert_end();
void insert_after_node_value();
void insert_before_node_value();
void insert_after_node_number();
void insert_before_node_number();
void insert_sortedlist();
void delete_begin();
void delete_end();
void delete_after_node_value();
void delete_before_node_value();
void delete_after_node_number();
void delete_before_node_number();
void search();
void reverse_list();
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
            new->link = NULL;
        }
        else
        {
            new->link = start;
            start = new;
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
            new->link = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->link != NULL)
            {
                ptr = ptr->link;
            }
            ptr->link = new;
            new->link = NULL;
        }
    }
}
void insert_after_node_value()
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
            ptr = start;
            int choice, found = 0;
            printf("Enter the value of choice after which you want to perform insertion : ");
            scanf("%d", &choice);
            while (ptr != NULL)
            {
                if (ptr->data == choice)
                {
                    found += 1;
                    break;
                }
                ptr = ptr->link;
            }
            if (found == 1)
            {
                new->link = ptr->link;
                ptr->link = new;
            }
            else
            {
                printf("There is no element of your choice after which you can perform insertion\n");
            }
        }
    }
}
void insert_before_node_value()
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
            int choice, found = 0;
            printf("Enter the value of choice before which you want to perform insertion : ");
            scanf("%d", &choice);
            while (ptr != NULL)
            {
                if (ptr->data == choice)
                {
                    found += 1;
                    break;
                }
                preptr = ptr;
                ptr = ptr->link;
            }
            if (found == 1)
            {
                if (ptr == start)
                {
                    new->link = ptr;
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
                printf("There is no element of your choice before which you can perform insertion\n");
            }
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
            while (ptr != NULL)
            {
                count++;
                if (count == choice)
                {
                    found += 1;
                    break;
                }
                ptr = ptr->link;
            }
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
            while (ptr != NULL)
            {
                count++;
                if (count == choice)
                {
                    found += 1;
                    break;
                }
                preptr = ptr;
                ptr = ptr->link;
            }
            if (found == 1)
            {
                if (ptr == start)
                {
                    new->link = ptr;
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
void insert_sortedlist()
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
            new->link = NULL;
        }
        else
        {
            node1 *preptr;
            ptr = start;
            if (new->data < ptr->data)
            {
                new->link = ptr;
                start = new;
            }
            else
            {
                while ((ptr != NULL) && (ptr->data < new->data))
                {
                    preptr = ptr;
                    ptr = ptr->link;
                }
                new->link = ptr;
                preptr->link = new;
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
    else if (start->link == NULL)
    {
        start = NULL;
    }
    else
    {
        start = start->link;
    }
    printf("\n");
}
void delete_end()
{
    if (start == NULL)
    {
        printf("Nothing to be deleted as ");
    }
    else if (start->link == NULL)
    {
        start = NULL;
    }
    else
    {
        node1 *preptr;
        ptr = start;
        while (ptr->link != NULL)
        {
            preptr = ptr;
            ptr = ptr->link;
        }
        preptr->link = NULL;
        free(ptr);
    }
    printf("\n");
}
void delete_after_node_value()
{
    if (start == NULL)
    {
        printf("Nothing to be deleted as ");
    }
    else
    {
        node1 *preptr;
        ptr = start;
        int choice, found = 0;
        printf("Enter the value of choice after which you want to perform deletion : ");
        scanf("%d", &choice);
        while (ptr != NULL)
        {
            preptr = ptr;
            if (ptr->data == choice)
            {
                found += 1;
                ptr = ptr->link;
                break;
            }
            ptr = ptr->link;
        }
        if (found == 1)
        {
            preptr->link = ptr->link;
        }
        else
        {
            printf("There is no  element after which we can perform deletion\n");
        }
        free(ptr);
    }
    printf("\n");
}
void delete_before_node_value()
{
    if (start == NULL)
    {
        printf("Nothing to be deleted as ");
    }
    else
    {
        node1 *preptr;
        ptr = start;
        int choice, found = 0;
        printf("Enter the value of choice before which you want to perform deletion : ");
        scanf("%d", &choice);
        while (ptr != NULL)
        {
            if (ptr->link->data == choice)
            {
                found += 1;
                break;
            }
            preptr = ptr;
            ptr = ptr->link;
        }
        if (found == 1)
        {
            if (ptr == start)
            {
                start = ptr->link;
            }
            else
            {
                preptr->link = ptr->link;
            }
        }
        else
        {
            printf("There is no  element before which we can perform deletion\n");
        }
        free(ptr);
    }
    printf("\n");
}
void delete_after_node_number()
{
    if (start == NULL)
    {
        printf("Nothing to be deleted as ");
    }
    else
    {
        node1 *preptr;
        ptr = start;
        int choice, found = 0, count = 0;
        printf("Enter the Number of Node after which you want to perform deletion : ");
        scanf("%d", &choice);
        if (start->link == NULL)
        {
            printf("There is no element after which we can perform deletion\n");
        }
        else
        {
            while (ptr != NULL)
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
            }
            if (found == 1)
            {
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
        printf("Nothing to be deleted as the List Is Empty!!");
    }
    else
    {
        node1 *preptr = NULL;
        ptr = start;
        int choice, found = 0, count = 1;
        // Here we have to make count = 1 because than only ptr will point on before node
        printf("Enter the Number of Node before which you want to perform deletion : ");
        scanf("%d", &choice);
        while (ptr != NULL)
        {
            count++;
            if (count == choice)
            {
                found += 1;
                break;
            }
            preptr = ptr;
            ptr = ptr->link;
        }
        if (found == 1)
        {
            if (ptr == start)
            {
                start = ptr->link;
            }
            else
            {
                preptr->link = ptr->link;
            }
        }
        else
        {
            printf("There is no  element before which we can perform deletion\n");
        }
        free(ptr);
    }
    printf("\n");
}
void search()
{
    if (start == NULL)
    {
        printf("The Linked-List is EMPTY\n");
    }
    else
    {
        int choice, found = 0, count = 0;
        printf("Enter the element to be searched : ");
        scanf("%d", &choice);
        ptr = start;
        while (ptr != NULL)
        {
            count++;
            if (ptr->data == choice)
            {
                found++;
                break;
            }
            ptr = ptr->link;
        }
        if (found == 1)
        {
            printf("The element is at %d node\n", count);
        }
        else
        {
            printf("No Element found your choice\n");
        }
    }
    printf("\n");
}
void reverse_list()
{
    if (start == NULL)
    {
        printf("The Linked-List is Emoty\n");
    }
    else
    {
        node1 *preptr = NULL, *temp;
        ptr = start;
        while (ptr != NULL)
        {
            temp = preptr;
            preptr = ptr;
            ptr = ptr->link;
            preptr->link = temp;
        }
        start = preptr;
    }
    display();
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
        while (ptr != NULL)
        {
            printf("Value = %d\nLink = %d\nNode_Address = %d\n\n", ptr->data, ptr->link, ptr);
            ptr = ptr->link;
        }
        printf("------------------------------------------------------------------------------\n");
    }
}
int main()
{
    int choice;
    do
    {
        printf("Press\n1-Insert_Begin\n2-Insert_End\n3-Insert_after_node_value\n4-Insert_before_node_value\n5-Insert_after_node_number\n6-Insert_before_node_number\n7-Insert_sortedlist\n8-Delete_Begin\n9 -Delete_End\n10-Delete_after_node_value\n11-Delete_before_node_value\n12-Delete_after_node_number\n13-Delete_before_node_number\n14-Search\n15-Reverse_list\n16-Display\n17-Exit : ");
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
            insert_after_node_value();
            break;

        case 4:
            insert_before_node_value();
            break;

        case 5:
            insert_after_node_number();
            break;

        case 6:
            insert_before_node_number();
            break;

        case 7:
            insert_sortedlist();
            break;

        case 8:
            delete_begin();
            break;

        case 9:
            delete_end();
            break;

        case 10:
            delete_after_node_value();
            break;

        case 11:
            delete_before_node_value();
            break;

        case 12:
            delete_after_node_number();
            break;
        case 13:
            delete_before_node_number();
            break;

        case 14:
            search();
            break;

        case 15:
            reverse_list();
            break;

        case 16:
            display();
            break;

        default:
            break;
        }
    } while (choice < 17);
    return 0;
}