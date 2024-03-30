#include <bits/stdc++.h>
#define nodeCount 100
using namespace std;

vector <int >G[nodeCount]; // stores the adjacent list
bool vis [ nodeCount ];
stack<int> s;

void dfs (int src, int n )
{
    vis[src] = true;
    for (int v:G[src])
    {
        if (! vis[v])
        {
            vis [v] = true ;
            dfs (v,n);
        }
    }
    s.push(src);
}

void visitAll (int n)
{
    for ( int i=0;i<n;i++)
    {
        if (!vis[i])
        {
            dfs(i,n);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()+1<<" ";
        s.pop();
    }
    cout<<endl;
}


int main()
{
    for(;;)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        memset(vis,false,sizeof(vis));
        memset(G,{},sizeof(G));

        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            G[a-1].push_back(b-1);
        }
        visitAll(n);
    }
    return 0;
}

