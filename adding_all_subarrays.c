/*
Adding all sub-arrays

Given an array of N integers and an integer K,
write a program that calculates the sum of every
sub-array of size K.
*/

#include <stdio.h>

int sum=0;

void main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int arr[N];
    for(int i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<K; i++)
    {
        sum += arr[i];
    }
    printf("%d ", sum);
    int aux = sum;
    for(int j=0; K!=N; j++, K++)
    {
        aux += arr[K];
        aux -= arr[j];
        printf("%d ", aux);
    }
}
