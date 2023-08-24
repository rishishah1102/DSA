// Swapping of two numbers with third variable
/*#include <stdio.h>
int main()
{
    int a=12,b=13,c;
    printf("Before Swapping a=%d and b=%d \n",a,b);
    c=a;
    a=b;
    b=c;
    printf("After Swapping a=%d and b=%d",a,b);
    return 0;
}

Swapping of two numbers without using third variable
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a=122,b=213;
    printf("Before Swapping a=%d and b=%d \n",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("After Swapping a=%d and b=%d",a,b);
    return 0;
}*/

// ---------------------------------------------------------------------------------------------

// Structure of libraries
/*#include <stdio.h>
struct library
{
    int id;
    char title[10];
    char author_name[10];
    int total_copies;
    int available_copies;
}b[3];
int main(int argc, char const *argv[])
{
    int eid;
    for (int i = 1; i <= 3; i++)
    {

        printf("ID = ");
        scanf("%d",&b[i].id);
        printf("Title = ");
        scanf("%s",&b[i].title);
        getchar();
        printf("Author Name = ");
        scanf("%s",&b[i].author_name);
        getchar();
        printf("Total Copies = ");
        scanf("%d",&b[i].total_copies);
        printf("Available Copies = ");
        scanf("%d",&b[i].available_copies);
        printf("\n");
    }
    for (int i = 1; i <= 3; i++)
    {
        printf("**The details of Book-%d :-",i);
        printf("ID = %d\n",b[i].id);
        printf("Title = %s\n",b[i].title);
        printf("Author Name = %s\n",b[i].author_name);
        printf("Total Copies = %d\n",b[i].total_copies);
        printf("\n");
    }
    printf("The available books are as follows :-\n");
    for (int i = 1; i <= 3; i++)
    {
        printf("%s - %d\n",b[i].title,b[i].available_copies);
    }
    printf("\n");
    printf("Enter the id of book which you want to read : ");
    scanf("%d",&eid);
    printf("\n");
    if (eid==b[1].id)
    {
        printf("The available books for this id is %d \n",b[1].available_copies);
    }
    else if (eid==b[2].id)
    {
        printf("The available books for this id is %d \n",b[2].available_copies);
    }
    else if (eid==b[3].id)
    {
        printf("The available books for this id is %d \n",b[3].available_copies);
    }
    else
    {
        printf("You have entered incorrect id please check your id and try again");
    }
    return 0;
}*/

// ---------------------------------------------------------------------------------------------

// Dynamic Memory Allocation
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("*** Malloc Function ***\n");
    int *p;
    int size, sum = 0, sum1 = 0, sum2 = 0, resize;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    p = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", (p + i));
    }
    for (int i = 0; i < size; i++)
    {
        sum += *(p + i);
    }
    printf("The sum of array is %d\n", sum);
    free(p);
    printf("\n");
    printf("*** Calloc Function ***\n");
    p = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", (p + i));
    }
    for (int i = 0; i < size; i++)
    {
        sum1 += *(p + i);
    }
    printf("The sum of array is %d\n", sum1);
    printf("\n");
    printf("*** Realloc Function ***\n");
label:
    printf("Enter the resize of array : ");
    scanf("%d", &resize);
    if (resize == size)
    {
        printf("The size of calloc and malloc are same so memory can be reallocated\n\n");
        goto label;
    }
    else
    {
        p = (int *)realloc(p, resize * sizeof(int));
        for (int i = 0; i < resize; i++)
        {
            printf("a[%d] = ", i);
            scanf("%d", (p + i));
        }
        for (int i = 0; i < resize; i++)
        {
            sum2 += *(p + i);
        }
        printf("The sum of array is %d\n", sum2);
        free(p);
    }
    return 0;
}