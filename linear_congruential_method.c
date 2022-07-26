// This program uses the Linear congruential method
// for generating random numbers.

#include <stdio.h>

#define m 100000000
#define m1 10000
#define b 31415821
static int a;
int mult(int p, int q)
{
    int p1, p0, q1, q0;
    p1 = p/m1; p0 = p%m1;
    q1 = q/m1; q0 = q%m1;
    return (((p0*q1+p1*q0) % m1)*m1+p0*q0) % m;
}
int random()
{
    a = (mult(a,b)+1) % m;
    return a;
}
main()
{
    int i, N;
    scanf("%d %d", &N, &a);
    for (i = 1; i <= N; i++) printf("%d ", random());
    printf("\n");
}
