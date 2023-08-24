// Binary Search Tree - Insertion and Traversal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insert_tree(int);
void insert_leftsubtree(int);
void insert_rightsubtree(int);
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
typedef struct node tree;
tree *root = NULL, *new, *ptr;
void insert_newnode()
{
    new = (tree *)malloc(sizeof(tree));
    if (new == NULL)
    {
        printf("Tree Overflow\n");
    }
    else
    {
        int value;
        printf("Enter the value to be inserted in tree : ");
        scanf("%d", &value);
        new->data = value;
        insert_tree(value);
    }
}
void insert_tree(int value)
{
    if (root == NULL)
    {
        root = new;
        root->left = NULL;
        root->right = NULL;
        printf("The value inserted in the root is %d\n", root->data);
    }
    else
    {
        if (new->data < root->data)
        {
            ptr = root;
            insert_leftsubtree(value);
        }
        else
        {
            ptr = root;
            insert_rightsubtree(value);
        }
    }
}
void insert_leftsubtree(int value)
{
    if (ptr->left == NULL && new->data < ptr->data)
    {
        ptr->left = new;
        new->left = NULL;
        new->right = NULL;
        printf("The value inserted in the root is %d\n", ptr->left->data);
    }
    else if (ptr->right == NULL && new->data > ptr->data)
    {
        ptr->right = new;
        new->left = NULL;
        new->right = NULL;
        printf("The value inserted in the root is %d\n", new->data);
    }
    else if (ptr->right != NULL && new->data > ptr->data)
    {
        ptr = ptr->right;
        insert_leftsubtree(value);
    }
    else
    {
        ptr = ptr->left;
        insert_leftsubtree(value);
    }
}
void insert_rightsubtree(int value)
{
    if (ptr->right == NULL && new->data > ptr->data)
    {
        ptr->right = new;
        new->left = NULL;
        new->right = NULL;
        printf("The value inserted in the root is %d\n", ptr->right->data);
    }
    else if (ptr->left == NULL && new->data < ptr->data)
    {
        ptr->left = new;
        new->left = NULL;
        new->right = NULL;
        printf("The value inserted in the root is %d\n", ptr->left->data);
    }
    else if (ptr->left != NULL && new->data < ptr->data)
    {
        ptr = ptr->left;
        insert_rightsubtree(value);
    }
    else
    {
        ptr = ptr->right;
        insert_rightsubtree(value);
    }
}
void preorder_traversal(tree *ptrr)
{
    if (ptrr == NULL)
    {
        return;
    }
    else
    {
        printf("Data = %d\n", ptrr->data);
        preorder_traversal(ptrr->left);
        preorder_traversal(ptrr->right);
    }
}
void inorder_traversal(tree *ptrr)
{
    if (ptrr == NULL)
    {
        return;
    }
    else
    {
        inorder_traversal(ptrr->left);
        printf("Data = %d\n", ptrr->data);
        inorder_traversal(ptrr->right);
    }
}
void postorder_traversal(tree *ptrr)
{
    if (ptrr == NULL)
    {
        return;
    }
    else
    {
        postorder_traversal(ptrr->left);    
        postorder_traversal(ptrr->right);
        printf("Data = %d\n", ptrr->data);
    }
} 
int main()
{
    int choice;
    do
    {
        printf("Press\n1-Insert elements in trees\n2-Preorder_Traversal\n3-Inorder_Traversal\n4-Postorder_Traversal : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_newnode();
            break;

        case 2:
            preorder_traversal(root);
            break;

        case 3:
            inorder_traversal(root);
            break;

        case 4:
            postorder_traversal(root);
            break;

        default:
            break;
        }
    } while (choice < 5);
    return 0;
}