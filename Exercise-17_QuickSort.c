#include <stdio.h>
void quicksort(int a[25], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (a[i] <= a[pivot])
            {
                i++;
            }
            while (a[j] > a[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}
int main()
{
    int i, N, arr[25];
    printf("Enter the size of the array : ");
    scanf("%d", &N);
    printf("Enter %d elements into the array :-\n", N);
    for (i = 0; i < N; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, N - 1);
    printf("The Sorted elements of the array is :-\n");
    for (i = 0; i < N; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}