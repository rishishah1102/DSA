// Searching - Linear Search and Binary Search

#include <stdio.h>
void sequential_search(int a[], int size)
{
    int search, i, found = 0;
    printf("Enter the element to be searched : ");
    scanf("%d", &search);
    for (i = 0; i < size; i++)
    {
        if (a[i] == search)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        printf("The element %d is at %d index\n\n", search, i);    
    }
    else
    {
        printf("There element is not found\n\n");
    }
}
void binary_search(int a[], int size)
{
    int search, low = 0, high = size - 1, middle, found = 0;
    printf("Enter the element to be searched : ");
    scanf("%d", &search);
    while (low <= high)
    {
        middle = (low + high)/2;
        if (a[middle] == search)
        {
            found = 1;
            break;
        }
        else if (a[middle] > search)
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
        
    }
    if (found == 1)
    {
        printf("The element %d is at %d index\n\n", search, middle);    
    }
    else
    {
        printf("There element is not found\n\n");
    }
}
int main()
{
    int arr[10];
    int choice, N;
    printf("Enter the size of the array : ");
    scanf("%d", &N);
    printf("Enter the elements in the array :-\n");
    for (int i = 0; i < N; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("Press 1-Sequential/Linear Search\n2-Binary Search : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            sequential_search(arr, N);
            break;

        case 2:
            binary_search(arr, N);
            break;

        default:
            break;
        }
    } while (choice < 3);
    return 0;
}