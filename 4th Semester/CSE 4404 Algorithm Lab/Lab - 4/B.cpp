#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0) break;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            pq.push(a);
        }
        long long int total = 0;
        while(!pq.empty())
        {
            if(pq.size()==1) break;
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int sum = a + b;
            total += sum;
            pq.push(sum);
        }
        cout<<total<<endl;
    }
}