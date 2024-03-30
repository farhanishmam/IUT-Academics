#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c,s,q,t=0;
    while(1)
    {
        t++;
        cin>>c>>s>>q;
        if(c==0 && s==0 && q==0)
            break;

        int adj[c+1][c+1];

        for(int i=0;i<=c;i++)
            for(int j=0;j<=c;j++)
                adj[i][j]=INT_MAX;

        for(int i = 0; i<s;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            adj[x][y]=w;
            adj[y][x]=w;
        }

        for(int k=1;k<=c;k++)
            for(int u=1;u<=c;u++)
                for(int v=1;v<=c;v++)
                    adj[u][v] = min(adj[u][v],max(adj[u][k],adj[k][v]));

        if(t!=1)
            cout<<"\n";
        cout<<"Case #"<<t;
        for(int i=0;i<q;i++)
        {
            int x,y;
            cin>>x>>y;
            if(adj[x][y]==INT_MAX)
            {
                cout<<"\n"<<"no path";
            }
            else
            {
                cout<<"\n"<<adj[x][y];
            }
        }
        cout<<"\n";
    }
}