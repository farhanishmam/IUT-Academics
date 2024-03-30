//Task 4
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k,x=0;
    cin>>n>>k;
    deque<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    make_heap(v.begin(),v.end());
    sort_heap(v.begin(),v.end());
    int trig = 0;
    while(1)
    {
        if(v[0]>=k)
        {
            break;
        }
        else if(v.size()==1)
        {
            trig = 1;
            break;
        }
        else
        {
            int a = v[0];
            int b = v[1];
            v.pop_front();
            v.pop_front();
            v.push_front(a+b*2);
            make_heap(v.begin(),v.end());
            sort_heap(v.begin(),v.end());
            x++;
        }
    }
    if(trig == 1) cout<<-1;
    else cout<<x;
}