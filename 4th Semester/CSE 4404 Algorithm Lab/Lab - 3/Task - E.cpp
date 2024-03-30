#include<bits/stdc++.h>
using namespace std;

bool visited[100] = {false};
bool dp[100] = {false};
bool func(int n)
{
    if(n<0) return false;
    else if(n==0) return true;
    if(visited[n] == true) return dp[n];
    dp[n] = (func(n-3) || func(n-7));
    visited[n] = true;
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(func(a)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}