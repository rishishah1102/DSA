#include <stdio.h>
#include <ctype.h>
#include <string.h>
void in_strfunc();
void out_strfunc1();
void out_strfunc2();
void stackfunc();
void push();
void pop();
char stack[20];
char in_str[20];
char out_str[20];
int top = -1;
int ptr1 = 0;
int ptr2 = 0;
int main()
{
    printf("Enter the input string : ");
    gets(in_str);
    printf("The input string is %s\n\n", in_str);
    in_strfunc();
    printf("The infix to postfix conversion is %s \n", out_str);
    return 0;
}
void in_strfunc()
{
    do
    {
        if (isalnum(in_str[ptr1]))
        {
            out_strfunc1();
        }
        else
        {
            stackfunc();
        }
        ptr1++;
    } while (in_str[ptr1] != '\0');
    do
    {
        pop();
    } while (top != -1);
}
void out_strfunc1()
{
    out_str[ptr2] = in_str[ptr1];
    ptr2++;
}
void stackfunc()
{
    if (top == -1)
    {
        push();
    }
    else if ((stack[top] == '(') && (in_str[ptr1] == '+' || in_str[ptr1] == '-' || in_str[ptr1] == '*' || in_str[ptr1] == '/' || in_str[ptr1] == '^'))
    {
        push();
    }
    else if ((stack[top] == '+' || stack[top] == '-') && (in_str[ptr1] == '+' || in_str[ptr1] == '-'))
    {
        pop();
        stackfunc();
    }
    else if ((stack[top] == '+' || stack[top] == '-') && (in_str[ptr1] == '*' || in_str[ptr1] == '/' || in_str[ptr1] == '^'))
    {
        push();
    }
    else if ((stack[top] == '*' || stack[top] == '/' || stack[top] == '^') && (in_str[ptr1] == '+' || in_str[ptr1] == '-' || in_str[ptr1] == '*' || in_str[ptr1] == '/'))
    {
        pop();
        stackfunc();
    }
    else if ((stack[top] == '*' || stack[top] == '/' || stack[top] == '^') && (in_str[ptr1] == '^'))
    {
        push();
    }
    else if ((stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/' || stack[top] == '^') && (in_str[ptr1] == '('))
    {
        push();
    }
    else if (in_str[ptr1] == ')')
    {
        do
        {
            pop();
        } while (stack[top] != '(');
        pop();
    }
    else
    {
        push();
    }
}
void push()
{
    top++;
    stack[top] = in_str[ptr1];
}
void pop()
{
    if (stack[top] == '(')
    {
        top--;
    }
    else
    {
        out_strfunc2();
        top--;
    }
}
void out_strfunc2()
{
    out_str[ptr2] = stack[top];
    ptr2++;
}