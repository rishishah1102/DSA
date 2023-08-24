/*
#include <stdio.h>
int factorial(int num)
{
    if (num < 2)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}
int gcd(int a, int b)
{
    int temp;
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        temp = a;
        a = b;
        b = temp;
        b = b % a;
        return gcd(a, b);
    }
}
int exponential(int x, int y)
{
    if (y == 1)
    {
        return x;
    }
    else
    {
        return x * exponential(x, y - 1);
    }
}
int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return n - 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main()
{
    int choice, num, a, b, x, y, n;
    printf("1-Factorial , 2-GCD , 3-Exponential , 4-Fibonnaci_Series : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the number you want to find the factorial : ");
        scanf("%d", &num);
        printf("The factorial of %d is %d ", num, factorial(num));
        break;

    case 2:
        printf("Enter the number a : ");
        scanf("%d", &a);
        printf("Enter the number b : ");
        scanf("%d", &b);
        if (a < b)
        {
            a = a + b;
            b = a - b;
            a = a - b;
        }
        printf("The gcd among %d and %d is %d", a, b, gcd(a, b));
        break;

    case 3:
        printf("Enter the number : ");
        scanf("%d", &x);
        printf("Enter the power : ");
        scanf("%d", &y);
        printf("The answer of %d^%d is %d", x, y, exponential(x, y));
        break;

    case 4:
        printf("Enter the value of  n : ");
        scanf("%d", &n);
        fibonacci(n);
        printf("The value of %d fibonnaci number is %d \n", n, fibonacci(n));
        break;

    default:
        printf("No such inputs");
        break;
    }
    return 0;
}
*/

// Tower of Hanoi
#include <stdio.h>
int TOH(int n, char source, char spare, char destination)
{
    if (n == 1)
    {
        printf("N = %d\nSource = %c\nSpare = %c\nDestination = %c\n\n", n, source, spare, destination);
        printf("Disc 1 is moved from %c rod to %c rod with respect to spare rod %c\n", source, destination, spare);
    }
    else
    {
        printf("N = %d\nSource = %c\nSpare = %c\nDestination = %c\n\n", n, source, spare, destination);
        TOH(n-1, source, destination, spare);
        printf("N = %d\nSource = %c\nSpare = %c\nDestination = %c\n\n", n, source, spare, destination);
        printf("Disc %d is moved from %c rod to %c rod with respect to spare rod %c\n", n, source, destination, spare);
        printf("N = %d\nSource = %c\nSpare = %c\nDestination = %c\n\n", n, source, spare, destination);
        TOH(n-1, spare, source, destination); 
    }
}
int main()
{
    int n;
    char source = 'a', spare = 'b', destination = 'c';
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("The process of disc getting transferred is as follows:-\n");
    TOH(n, source, spare, destination);
    return 0;
}
// TOH(3,A,B,C)
// TOH(2,A,C,B)
// TOH(1,A,B,C)
// TOH(1,C,A,B)
// TOH(1,B,C,A)
// TOH(2,B,A,C)
// TOH(1,A,B,C)