#include <bits/stdc++.h>
using namespace std;

void bfs (int src, const vector<int> alist[], int ver)
{
    vector<int> level(ver, -1) ;
    vector<int> parent(ver, -1);
    vector<bool> vis(ver, false);
    queue <int>q;
    q.push(src);
    vis [ src ] = true ;
    level [ src ] = 0;
    parent [ src ] = -1;
    while (!q. empty ())
    {
        int u = q. front ();
        q. pop ();
        for (int v : alist[u])
        {
            if (! vis[v])
            {
                vis [v] = true ;
                level [v] = level [u] + 1;
                parent [v] = u;
                q. push (v);
            }
        }
    }
    for(int i=0;i<ver;i++)
    {
        if(level[i] == 0) continue;             //skipping for source node
        if(level[i] == -1) cout<<-1<<" ";       //-1 for unreachable nodes
        else cout<<level[i]*6<<" ";             //weight is 6
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        vector <int> adj_list[v];
        for(int i = 0; i<e; i++)
        {
            int a,b;
            cin>>a>>b;
            adj_list[a-1].push_back(b-1);
            adj_list[b-1].push_back(a-1);
        }
        int src;
        cin>>src;
        bfs(src-1,adj_list,v);
    }
}
