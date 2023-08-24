// Print Natural Number
/*#include <stdio.h>
void naturalnumber(int num, int i)
{
    if (i == num)
    {
        printf("%d \n", i);
    }
    else
    {
        printf("%d \n", i);
        naturalnumber(num, i + 1);
    }
}
int main()
{
    int n, i = 1;
    printf("Enter how many natural numbers you want to print : ");
    scanf("%d", &n);
    naturalnumber(n, i);
    return 0;
}
*/

// Print the total number of digit in a number
/*#include <stdio.h>
int countdigit(int num, int count)
{
    if (num == 0)
    {
        return count;
    }
    else
    {
        num = num/10;
        count++;
        countdigit(num, count);
    }
    
}
int main()
{
    int num, count = 0;
    printf("Enter any number : ");
    scanf("%d", &num);
    printf("The number of digits in a number is %d\n", countdigit(num, count));
    return 0;
}
*/

// Print sum of digit of an entered number by an user
/*#include <stdio.h>
int sumofdigit(int num)
{
    int digit;
    if (num == 0)
    {
        return num;
    }
    else
    {
        digit = num%10;
        num = num/10;
        return sumofdigit(num) + digit;
    }
    
}
int main()
{
    int num;
    printf("Enter any number : ");
    scanf("%d", &num);
    printf("The sum of digits of an entered number is %d\n", sumofdigit(num));
    return 0;
}
*/

// Reverse String using recursion
#include <stdio.h>
#include <string.h>
void reverse(char [], int, int);
int main()
{
    char str[20];
    int size,i = 0;
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    size = strlen(str);
    reverse(str, i, size - 1);
    printf("The string after reversing is: %s\n", str);
    return 0;
}
void reverse(char str1[], int index, int size)
{
    char temp;
    temp = str1[index];
    str1[index] = str1[size - index];
    str1[size - index] = temp;
    if (index == size / 2)
    {
        return;
    }
    reverse(str1, index + 1, size);
}