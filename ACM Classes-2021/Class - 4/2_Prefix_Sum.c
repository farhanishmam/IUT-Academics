#include<stdio.h>

int query(int a, int b, int sum[])
{
    return sum[b] - sum[a-1];
}

int main()
{
    int arr[1001];
    int sum_arr[1001];
    sum_arr[0] = 0;
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        sum_arr[i] = sum_arr[i-1] + arr[i];
    }
    int q;
    scanf("%d", &q);
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%d %d", &a,&b);
        printf("%d",query(a,b, sum_arr));
    }
}
