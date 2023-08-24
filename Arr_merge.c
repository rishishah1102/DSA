#include <stdio.h>
void merge();
int main()
{
    int a[10], size1;
    printf("Enter the size of array-1 : ");
    scanf("%d", &size1);
    printf("Enter the elements of array-1 : \n");
    for (int i = 0; i < size1; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    int b[10], size2;
    printf("Enter the size of array-2 : ");
    scanf("%d", &size2);
    printf("Enter the elements of array-1 : \n");
    for (int i = 0; i < size2; i++)
    {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }
    merge(a, size1, b, size2);
    return 0;
}
void merge(int a[], int s1, int b[], int s2)
{
    int temp;
    int c[20], s3;
    s3 = s1 + s2;
    for (int i = 0; i < s1; i++)
    {
        c[i]=a[i];
    }
    for (int i = 0; i < s3; i++)
    {
        c[i+s1]=b[i];
    }
    for (int i = 0; i < s3; i++)
    {
        for (int j = i+1; j < s3; j++)
        {
            if (c[i]>c[j])
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }
    printf("The merged and sorted array is :-\n");
    for (int i = 0; i < s3; i++)
    {
        printf("c[%d] = %d \n",i,c[i]);
    }
}