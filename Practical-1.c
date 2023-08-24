// Swapping of two nunbers using call by value
// #include <stdio.h>
// int swap(int a,int b)
// {
//     int temp;
//     temp=a;
//     a=b;
//     b=temp;
//     printf("After Swapping a = %d and b = %d",a,b);
//     return 0;
// }
// int main(int argc, char const *argv[])
// {
//     int a=10,b=13;
//     printf("Before Swapping a = %d and b = %d\n",a,b);
//     swap(a,b);
//     return 0;
// }

// Swapping of two nunbers using call by reference
// #include <stdio.h>
// int swap(int *a,int *b)
// {
//     int c;
//     c=*a;
//     *a=*b;
//     *b=c;
//     printf("After Swapping a = %d and b = %d",*a,*b);
//     return 0;
// }
// int main(int argc, char const *argv[])
// {
//     int a=25,b=15;
//     printf("Before Swapping a = %d and b = %d\n",a,b);
//     swap(&a,&b);
//     return 0;
// }