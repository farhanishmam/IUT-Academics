#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

long long int arr[120];
long long int dp[120][1001];


int main()
{
    int n,k;

    cin>>n>>k;

    for(int i=0;i<n;i++)
    {   int x;
        cin>>x;
        arr[x]++;
    }

    for(int i=0;i<110;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=109;i++)

    {
        for(int j=1;j<=k;j++)
        {
		dp[i][j]=(arr[i]*(dp[i-1][j-1])+dp[i-1][j])%mod;
        }
    }

    cout<<dp[109][k];
}