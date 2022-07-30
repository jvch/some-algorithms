// Gives the last number of the Fibonacci sequence
// and the number of calls to the recursive function.

#include <stdio.h>

int aux=0, fib=0;

int funcion(int n)
{
    if(n==0)
    {
        fib=0;
        aux++;
    }
    else if(n==1)
    {
        fib=1;
        aux++;
    }
    else
    {
        fib=funcion(n-1)+funcion(n-2);
        aux++;
    }
    return fib;
}

void main()
{
    int N;
    scanf("%d", &N);
    int fib2 = funcion(N);
    printf("%d %d", fib2, aux);
}