#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> vec, int l, int r, int x)
{
    while (l <= r)  //terminating condition
    {
        int m = l + (r - l) / 2; //find mid
        if (vec[m] == x) //found at mid
            return m;
        if (vec[m] < x)  //look at right
            l = m + 1;   //update left
        else                //look at left
            r = m - 1;   //update right
    }
    return -1; //couldn't find
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    map<int, bool> mp;
    for(int i = 0; i<n ;i++)
    {
        int a;
        scanf("%d",&a);
        if(mp[a]==0)
        {
            vec.push_back(a);
            mp[a] = 1;
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a;
        scanf("%d",&a);
        int idx1, idx2;
        int sz = vec.size();
        if(binarySearch(vec,0,sz-1,a)!=-1)
        {
            idx1 = binarySearch(vec,0,sz-1,a);
            idx2 = idx1;
        }
        else
        {
            idx1 = lower_bound(vec.begin(),vec.end(),a) - vec.begin();
            idx2 = upper_bound(vec.begin(),vec.end(),a) - vec.begin() - 1;
        }
        if(idx1 == 0)
            cout<<"X"<<" ";
        else
            cout<<vec[idx1-1]<<" ";
        if(idx2 == sz-1)
            cout<<"X"<<endl;
        else
            cout<<vec[idx2+1]<<endl;
    }
}
