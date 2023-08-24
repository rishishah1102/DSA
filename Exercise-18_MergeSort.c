#include <stdio.h>
void mergesort(int [], int, int, int);
int size;
void merge(int a[size], int lb, int ub)
{
    int middle;
    if (lb < ub)
    {
        middle = (lb + ub)/2;
        merge(a, lb, middle);
        merge(a, middle + 1, ub);
        mergesort(a, lb , middle, ub);
    }
}
void mergesort(int a[size], int lb, int middle, int ub)
{
    int i = lb, j = middle + 1, k = lb;
    int b[size];
    while (i <= middle && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];  
            j++;  
        }
        k++;
    }
    if (i > middle)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= middle)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (int l = lb; l <= ub; l++)
    {
        a[l] = b[l];
    }
}
int main()
{
    int arr[10];
    int N;
    printf("Enter the size of the array : ");
    scanf("%d", &N);
    size = N;
    printf("Enter the elements in the array :-\n");
    for (int i = 0; i < N; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    merge(arr, 0, N-1);
    printf("The sorted array is:-\n");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}