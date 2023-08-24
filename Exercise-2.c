#include <stdio.h>
void arr_insert();
void arr_delete();
void arr_search();
void arr_sort();
void arr_traverse();
int size;
int main()
{
    int arr[10], a;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]= ", i);
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("Enter 1->Insert 2->Delete 3->Search 4->Sorting 5->Traverse : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            arr_insert(&arr[0]);
            break;
        case 2:
            arr_delete(&arr[0]);
            break;
        case 3:
            arr_search(&arr[0]);
            break;
        case 4:
            arr_sort(&arr[0]);
            break;
        case 5:
            arr_traverse(&arr[0]);
            break;
        default:
            break;
        }
    } while (a != 6);
    return 0;
}
void arr_insert(int a[])
{
    int pos, num;
    printf("Enter the position you want to insert an element in array : ");
    scanf("%d", &pos);
    printf("Enter the number you want to insert in array : ");
    scanf("%d", &num);
    if (pos > 10)
    {
        printf("The element can not be inserted in an array\n");
    }
    else
    {
        if (pos > size)
        {
            goto ENTER;
        }
        for (int i = size - 1; i >= pos - 1; i--)
        {
            a[i + 1] = a[i];
        }
    ENTER:
        a[pos - 1] = num;
        size++;
        arr_traverse(&a[0]);
    }
}
void arr_delete(int a[])
{
    int pos;
    printf("Enter the position you want to delete an element in array : ");
    scanf("%d", &pos);
    if (pos > size)
    {
        printf("There is not element at that position for deletion\n");
    }
    else
    {
        for (int i = pos - 1; i < size; i++)
        {
            a[i] = a[i + 1];
        }
        size--;
        arr_traverse(&a[0]);
    }
}
void arr_search(int a[])
{
    int search, found = 0, b;
    printf("Enter the element you want to search : ");
    scanf("%d", &search);
    for (int i = 0; i < size; i++)
    {
        if (a[i] == search)
        {
            found += 1;
            b = i;
            break;
        }
    }
    if (found == 1)
    {
        printf("a[%d]=%d\n", b, search);
    }
    else
    {
        printf("There is no element of that number");
    }
}
void arr_sort(int a[])
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf(" The sorting in ascending order is :- ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
    printf(" The sorting in descending order is :- ");
    for (int i = size - 1; i >= 0; i--)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}
void arr_traverse(int a[])
{
    printf("The value of array is as follows :-\n");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d]=%d\n", i, a[i]);
    }
}