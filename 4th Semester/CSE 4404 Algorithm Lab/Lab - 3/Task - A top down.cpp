#include<bits/stdc++.h>
#define SIZE 1001
using namespace std;

int dp[SIZE][SIZE];

int func(char x[], char y[], int m, int n)
{
    if(m==0 || n==0) return 0;
    if (x[m - 1] == y[n - 1])
        dp[m][n] = func(x,y,m-1,n-1) + 1;
    else
        dp[m][n] = max(func(x,y,m-1,n), func(x,y,m,n-1));
    return dp[m][n];
}

int main()
{
    char x[SIZE],y[SIZE];
    int i, j;
    while (gets(x) && gets(y))
    {
        int xlen = strlen(x);
        int ylen = strlen(y);
        cout << func(x,y,xlen,ylen)<<endl;
    }
}
