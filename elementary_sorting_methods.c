// Read in N numbers and then call a subroutine to sort them.

#include <stdio.h>

#define maxN 100

// sorts the first three numbers
sort3(int a[], int N)
{
    int t;
    if(a[1]>a[2])
    {
        t=a[1]; a[1]=a[2]; a[2]=t;
    }
    if(a[1] > a[3])
    {
        t=a[1]; a[1]=a[3]; a[3]=t;
    }
    if(a[2]>a[3])
    {
        t=a[2]; a[2]=a[3]; a[3]=t;
    }
}

// selection sort
selection(int a[], int N)
{
    int i, j, min, t;
    for(i=1; i<N; i++)
    {
        min=i;
        for(j=i+1; j<=N; j++)
            if(a[j]<a[min]) min=j;
        t=a[min]; a[min]=a[i]; a[i]=t;
    }
}

// insertion sort
insertion(int a[], int N)
{
    int i, j, v;
    for(i=2; i<=N; i++)
    {
        v=a[i]; j=i;
        while(a[j-1]>v)
        {
            a[j]=a[j-1]; j--;
        }
        a[j]=v;
    }
}

// bubble sort
bubble(int a[], int N)
{
    int i, j, t;
    for(i=N; i>=1; i--)
        for(j=2; j<=i; j++)
        {
           if(a[j-1]>a[j])
           {
               t=a[j-1]; a[j-1]=a[j]; a[j]=t;
           }
        }
}

// shellsort
shellsort(int a[], int N)
{
    int i, j, h, v;
    for(h=1; h<=N/9; h=3*h+1);
    for( ;h>0; h/=3)
    {
        for(i=h+1; i<=N; i+=1)
        {
            v=a[i]; j=i;
            while(j>h && a[j-h]>v)
            {
                a[j]=a[j-h]; j-=h;
            }
            a[j]=v;
        }
    }
}

main()
{
    int N, i, a[maxN+1];
    N=0; while(scanf("%d", &a[N+1])!=EOF) N++;
    a[0]=0; sort3(a, N);
    for(i=1; i<=N; i++)
        printf("%d ", a[i]);
    printf("\n");
}
