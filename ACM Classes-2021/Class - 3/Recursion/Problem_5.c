#include <stdio.h>
#include <math.h>

int sum_poly(int i, int n, int x)
{
    if(n==0)
        return 1;
    if(i<n)
        return (int)pow(x,i) + sum_poly(i+1, n, x);
    return 0;
}

int main()
{
    int n, v, x;
    scanf("%d %d", &x, &n);
    v = sum_poly(0, n, x);
    printf("%d\n", v);
    return 0;
}