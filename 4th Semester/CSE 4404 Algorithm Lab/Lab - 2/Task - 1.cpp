#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define INF 1e6

void dijkstra(int src, long long int dist[], vector<pii> G[])
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        int sz = G[u].size();
        for(int ii = 0; ii < sz; ii++)
        {
            int vw = G[u][ii].first;
            int v = G[u][ii].second;
            long long int cost = dist[u] + vw;
            if(dist[v] > cost)
            {
                dist[v] = cost;
                pq.push(make_pair(cost,v));
            }
        }

    }
}

int main(void)
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int n,m,s,t;
        cin>>n>>m>>s>>t;
        vector<pii> G[n];
        long long int dist[n];
        memset(dist,INF,sizeof(dist));
        for(int j=0;j<m;j++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            G[a].push_back(make_pair(w,b));
            G[b].push_back(make_pair(w,a));
        }
        dijkstra(s,dist,G);
        if(dist[t]>=INF || m==0) printf("Case #%d: unreachable\n",i+1);
        else printf("Case #%d: %lld\n",i+1,dist[t]);
    }
}