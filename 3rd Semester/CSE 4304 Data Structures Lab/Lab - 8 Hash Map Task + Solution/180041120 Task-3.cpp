#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void)
{
    int m;
    cin>>m;
    if(m<=0 || m>=100)
    {
        cout<<"Invalid Input"<<endl;
    }
    else
    {
        int n;
        unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        for(int i=0;i<m;i++)
        {
            int a;
            cin>>a;
            mp[a]++;
        }
        cin>>n;
        for(auto it = mp.begin();it != mp.end();it++)
        {
            int a = it->first;
            int b = n - it->first;
            if(((a==b) && (mp[a]>=2))||(mp[b]>0 && mp[a]>0 && a!=b))
            {
                mp[a]--;
                mp[b]--;
                v.push_back(make_pair(a,b));
            }
        }
        if(v.empty())
        {
            cout<<"No pairs found"<<endl;
        }
        else
        {
            cout<<"Pairs with sum "<<n<<" are: ";
            for(auto it = v.begin();it != v.end();it++)
            {
                cout<<"("<<it->first<<","<<it->second<<")";
                if(it!=v.end()-1)
                {
                    cout<<",";
                }
            }
        }
    }
}