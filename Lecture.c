#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[5] = {8, 2, 7, 4, 5};
    int *p;
    // p=&a;
    // p=a;
    p=&a[0];
    for (int i = 0; i < 5; i++)
    {
        printf("*p=%d *p=%d *p=%d *p=%d \n", p[i],*(p+i),i[p],*(i+p));
    }
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("p=%d p=%d p=%d p=%d \n", &p[i],p+i,&i[p],i+p);
    // }
    return 0;
}

// p[i],*(p+i),i[p],*(i+p) will gave same output and also if we dont define pointer and we take a[i],*(a+i),i[a],*(i+a) will also gave same output as above pointer.The array will work as pointer even though we dont define it.

// Passing array as a pointer
/*#include <stdio.h>
void get_arr();
void get2_arr();
int main(int argc, char const *argv[])
{
    int a[5] = {8, 2, 7, 4, 5};
    get_arr(a);
    get2_arr(a);
    return 0;
}
void get_arr(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("a=%d  \n",a[i]);
    }
}
// OR
void get2_arr(int* a)
{
    for (int i = 0; i < 5; i++)
    {
        printf("a=%d  \n",a[i]);
    }
}*/