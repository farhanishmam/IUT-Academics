#include<bits/stdc++.h>
#define lld unsigned long long int
#define N 100000
using namespace std;
 
int main()
{
    lld total_arr[N+1] = {0};
    lld mem[N+1] = {0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        total_arr[a] += a;
        mem[a] = total_arr[a];
    }
    mem[0] = total_arr[0];
    mem[1] = total_arr[1];
    for(int i=2;i<=N;i++)
    {
        mem[i] = max(mem[i] + mem[i-2], mem[i-1]);
    }
    cout<<mem[N]<<endl;
}