#include <stdio.h>

int factorial_recursion(int n);
int factorial_loops(int n);

int main()
{
    int n;
    printf("Enter n of which factorial has to be calculated :\n");
    scanf("%d", &n);
    printf("Factorial using recursion is : %d\n", factorial_recursion(n));
    factorial_loops(n);
}

int factorial_recursion(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    int factorialNminus1 = factorial_recursion(n - 1);
    int factorial = factorialNminus1 * n;
    return factorial;
}

int factorial_loops(int n)
{
    int factorial = 1;
    for (int i = n; i >= 1; i--)
    {
        factorial = factorial * i;
    }
    printf("Factorial using loops is : %d\n", factorial);

    return 0;
}