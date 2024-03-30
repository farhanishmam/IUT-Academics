#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    stack<int> s;
    int j = 1;
    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a==j)
        {
            j++;
        }
        else s.push(a);
    }
    int b;
    cin>>b;
    int label = 0;
    while(!s.empty())
    {
        if(j==s.top())
        {
            j++;
            s.pop();
            label = 1;
        }
        else
        {
            label = 0;
            break;
        }
    }
    if(label) cout<<"Yes";
    else cout<<"No";
}
