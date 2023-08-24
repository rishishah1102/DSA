// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     // This code demonstrates the addition of array statically
//     int arr[5]={1,2,3,4,5},sum=0;
//     for (int i = 0; i < 5; i++)
//     {
//         sum += arr[i];
//     }
//     printf("The sum of array statically is %d\n",sum);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
int main()
{    
    // This code demonstrates the addition of array dynamically
    int *p;
    int size,sum=0;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    p=(int*)calloc(size,sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",(p+i));
    }
    for (int i = 0; i < size; i++)
    {
        sum += *(p+i);
    }
    printf("The sum of array dynamically is %d",sum);
    free(p);
    return 0;
}
