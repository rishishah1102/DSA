#include <stdio.h>
void selectionsort(int a[], int size)
{
    int i, j, temp, min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
                // printf("%d\n", min);
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("The sorted array is:-\n");
    for (int i = 0; i < size; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
}
int main()
{
    int arr[10];
    int N;
    printf("Enter the size of the array : ");
    scanf("%d", &N);
    printf("Enter the elements in the array :-\n");
    for (int i = 0; i < N; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    selectionsort(arr, N);
    return 0;
}