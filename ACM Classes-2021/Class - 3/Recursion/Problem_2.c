#include <stdio.h>

void print(int i, int j, int a[100])
{
    if(i<=j)
    {
        printf("%d %d\n", a[i], a[j]);
        print(i+1, j-1, a);
    }
}

int main()
{
    int i, n, a[100];
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    print(0, n-1, a);
    return 0;
}
