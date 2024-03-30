#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        vector< pair<int,int> > v;
        stack< pair<int,int> > s;
        for(;;)
        {
            int a;
            cin>>a;
            if(a==-1) break;
            else
            {
                v.push_back(make_pair(a,-1));
            }
        }
        for(int i=0;i<v.size();i++)
        {
            if(s.size()==0) s.push(make_pair(v[i].first,i));
            else if((s.top().first)<v[i].first)
            {
                while(1)
                {
                    if(s.size()==0)
                    {
                        s.push(make_pair(v[i].first,i));
                        break;
                    }
                    else if((s.top().first)<v[i].first)
                    {
                        int p = s.top().second;
                        v[p].second = v[i].first;
                        s.pop();
                    }
                    else
                    {
                        s.push(make_pair(v[i].first,i));
                        break;
                    }
                }
            }
            else
            {
                s.push(make_pair(v[i].first,i));
            }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].second<<" ";
        }
        cout<<endl;
    }
}