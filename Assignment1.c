// 2-D Array Program
/*
#include <stdio.h>
int main()
{
    int s[5][4];
    int sum = 0;
    printf("Enter the sales of each city and product:-\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &s[i][j]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf(" %d ", s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("SALES OF CITY BY EACH PRODUCT  :- \n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum += s[i][j];
        }
        printf("The sales of city-%d is %d \n",i+1,sum);
        sum=0;
    }
    printf("\n");
    printf("SALES OF PRODUCT IN EACH CITY :- \n");
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            sum += s[i][j];
        }
        printf("The sales of product-%d is %d \n",j+1,sum);
        sum=0;
    }
    printf("\n");
    printf("TOTAL SALES OF COMPANY :- \n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum += s[i][j];
        }
    }
    printf("The total sales of company is %d",sum);
    return 0;
}
*/

// The transpose of matrix has been done in 2D Array operation 

// 2-D Array Operation
#include <stdio.h>
int main()
{
    int a[5][5];
    int b[5][5];
    int c[5][5];
    int m1, n1, m2, n2, o, sum = 0;
    printf("The rows and column of Matrix A is as follows :- \n");
    printf("Enter m1 : ");
    scanf("%d", &m1);
    printf("Enter n1 : ");
    scanf("%d", &n1);
    printf("The rows and column of Matrix B is as follows :- \n");
    printf("Enter m2 : ");
    scanf("%d", &m2);
    printf("Enter n2 : ");
    scanf("%d", &n2);
    printf("Input elements of Matrix A :- \n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("The Matrix A is :- \n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Input elements of Matrix B :- \n");
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    printf("The Matrix B is :- \n");
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("Enter 1-Addition , 2-Subtraction , 3-Transpose , 4-Multiplication : ");
    scanf("%d", &o);
    switch (o)
    {
    case 1:
        if (m1 == m2 && n1 == n2)
        {
            printf("The Addition of Matrix is :- \n");
            for (int i = 0; i < m1; i++)
            {
                for (int j = 0; j < n2; j++)
                {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
            for (int i = 0; i < m2; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("The Matrix addition is not possible \n");
        }
        break;

    case 2:
        if (m1 == m2 && n1 == n2)
        {
            printf("The Subtraction of Matrix is :- \n");
            for (int i = 0; i < m1; i++)
            {
                for (int j = 0; j < n2; j++)
                {
                    c[i][j] = a[i][j] - b[i][j];
                }
            }
            for (int i = 0; i < m2; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("The Matrix Subtractiion is not possible \n");
        }
        break;

    case 3:
        printf("The matrix A' or Transpose of Matrix A is :- \n");
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                c[j][i] = a[i][j];
            }
        }
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m1; j++)
            {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
        break;
        
    case 4:
        if (n1 == m2)
        {
            printf("The Matrix Multiplication is :- \n");
            for (int i = 0; i < m1; i++)
            {
                for (int j = 0; j < n2; j++)
                {
                    for (int k = 0; k < n1; k++)
                    {
                        sum = sum + (a[i][k]) * (b[k][j]);
                    }
                    c[i][j] = sum;
                    sum = 0;
                }
            }
            for (int i = 0; i < m1; i++)
            {
                for (int j = 0; j < n2; j++)
                {
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("Matrix cannot be multiplied");
        }
        break;

    default:
        break;
    }
    return 0;
}