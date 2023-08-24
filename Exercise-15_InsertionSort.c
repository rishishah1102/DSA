#include <stdio.h>
void insertionsort(int a[], int size)
{
    int temp;
    for (int i = 1; i < size; i++)
    {
        temp = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > temp; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
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
    insertionsort(arr, N);
    return 0;
}