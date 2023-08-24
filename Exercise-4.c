// the first practical of infix to postfix consversion is in the practical-5

// Evaluating postfix conversion
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
void in_str();
void evaluation(float, float);
void push();
void pop();
char postfix[20];
float stack[20];
int top = -1;
int ptr1 = 0;
float answer = 0;
int main()
{
    printf("Enter the postfix expression : ");
    gets(postfix);
    in_str();
    printf("The evaluation of postfix expression is %0.4f \n", answer);
    return 0;
}
void in_str()
{
    do
    {
        if (isalnum(postfix[ptr1]))
        {
            push();
        }
        else
        {
            pop();
        }
        ptr1++;
    } while (postfix[ptr1] != '\0');
    answer = stack[top];
    top--;
}
void push()
{
    top++;
    stack[top] = postfix[ptr1] - '0';
}
void pop()
{
    float a, b;
    b = stack[top];
    top--;
    a = stack[top];
    top--;
    evaluation(a, b);
}
void evaluation(float n1, float n2)
{
    if (postfix[ptr1] == '+')
    {
        answer = n1 + n2;
        top++;
        stack[top] = answer;
    }
    else if (postfix[ptr1] == '-')
    {
        answer = n1 - n2;
        top++;
        stack[top] = answer;
    }
    else if (postfix[ptr1] == '*')
    {
        answer = n1 * n2;
        top++;
        stack[top] = answer;
    }
    else if (postfix[ptr1] == '/')
    {
        answer = n1 / n2;
        top++;
        stack[top] = answer;
    }
    else if (postfix[ptr1] == '^')
    {
        answer = pow(n1, n2);
        top++;
        stack[top] = answer;
    }
}