#include<stdio.h>

int query(int a, int b, int arr[])
{
    return arr[b] - arr[a-1];
}


int main()
{
    int arr[1001];
    int sum_arr[1001];
    sum_arr[0] = 0;

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        sum_arr[i] = arr[i] + sum_arr[i-1];
    }
    int q;
    scanf("%d", &q);
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        int result = query(a,b, sum_arr);
        printf("%d\n", result);
    }
}
