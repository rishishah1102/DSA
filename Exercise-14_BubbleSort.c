#include <stdio.h>
void bubblesort(int a[], int size)
{
    int temp, flag = 0;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
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
    bubblesort(arr, N);
    return 0;
}