#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;        //representative map

int find_set(int x)
{
    if(mp[x] == x)
        return x;
    else return mp[x] = find_set(mp[x]);    //changing representative of traversed nodes
}

void dsu(int x,int y)
{
    int p_x = find_set(x);  //representative of x
    int p_y = find_set(y);  //representative of y
    //we don't need to check p_x == p_y because, the max would just reassign the same representative if they are equal
    mp[max(p_x,p_y)] = min(p_x,p_y); //the smaller representative has been set as representative of larger one
}

int main()
{
    int n,m;
    cin>>n>>m;

    set<int> s1,s2;
    vector<pair<int,int>> v;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        s1.insert(x);
        s1.insert(y);

        mp[x] = x;  //storing in representative map to update representatives
        mp[y] = y;

        v.push_back(make_pair(x,y)); //storing in vector pair to perform dsu
    }

    for(int i=0;i<m;i++)        //dsu on every pair of points
    {
        dsu(v[i].first,v[i].second);
    }
    //in a set, no elements are repeated
    //so, for every element which was part of the edge, we insert it in our set and find its representative

    for(auto q:s1)
    {
        s2.insert(find_set(q)); //s2 contains all the representatives
    }

    cout<<n-s1.size()+s2.size()<<endl;  //from total nodes , we subtract the number of connected nodes 
                                        //and add the number of representatives to it 

    return 0;
}