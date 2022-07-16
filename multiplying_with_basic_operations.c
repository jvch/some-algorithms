/*
Multiplying integers with more basic operations

You bought a very old computer in a garage sale.
The CPUY of this computer has many limitations:
although it can add, multiply by 2 and divide by 2 (with integers),
it cannot multiply arbitrary values (for example, the CPU can
calculate 5/2, 5*2, 5+7 but not 5*7). Being an expert programmer,
you design a recursive algorithm producto(a,b) that allows a*b
multiplications and that only needs the operations that the CPU
can do:

    . If a=0 then producto(a,b)=0.
    . If a>0 and a is pair, then
      producto(a,b)=2*producto(a/2,b).
    . If a>0 and a is odd, then
      producto(a,b)=2*producto(a/2,b)+b.

Write a program that calculates how many aritmatic operations
(addition, multiplications by 2, divisions by 2) it need the
previous algorithm to get the product of two numbers.
The parity detection of a is given and it doesn't need to
be counted.
*/

#include <stdio.h>

int aux = 0;

int producto(int a, int b)
{
    if (a==0)
    {
        aux+=0;
    }
    else if (a>0 && a%2==0)
    {
        2*(producto((a/2),b));
        aux+=2;
    }
    else if (a>0 && a%2==1)
    {
        2*(producto((a/2),b))+b;
        aux+=3;
    }
    return aux;
}

void main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = producto(a, b);
    printf("%d", c);
}
