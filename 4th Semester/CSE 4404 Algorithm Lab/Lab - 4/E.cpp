#include<bits/stdc++.h>
using namespace std;

int func(int arr[])
{
    int count = 0;
    int prev_start = 0;
    for(int i=1;i<11;i++)
    {
        if(arr[i] == -1) continue;
        if(arr[i] >= prev_start)
        {
            count++;
            prev_start = i;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int arr[11];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<11;j++)
        {
            arr[j] = -1;
        }
        int a,b;
        while(1)
        {
            cin>>a>>b;
            if(a==0 && b==0) break;
            if(arr[b]<a) arr[b] = a;
        }
        cout<<func(arr)<<endl;
    }
}