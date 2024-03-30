#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int coins[100];
    int dp[50001];
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>coins[i];
            sum += coins[i];
        }
        memset(dp,0,sizeof(dp));
        int half = sum/2;
        for (int i=0;i<n;i++)
        {
            for (int j=half;j>=coins[i];j--)
                dp[j]=max(dp[j], dp[j-coins[i]] + coins[i]);
        }
        cout<<sum - 2*dp[half]<<endl;
    }

    return 0;
}