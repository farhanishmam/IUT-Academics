#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define INF 1e6
using namespace std;

void dijkstra(vector<pii> adjList[], int dist[], int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        int len = adjList[u].size();

        for (int i=0;i<len;i++)
        {
            int v = adjList[u][i].second;
            int vw = adjList[u][i].first;

            if (dist[v] > max(vw,dist[u]))
            {
                dist[v] = max(vw,dist[u]);
                pq.push({dist[v],v});
            }
        }
    }
}


int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int n,m,src;
        scanf("%d %d",&n,&m);
        vector<pii> G[n];               //adjacency list
        map<pii,int> best_cost;
        for(int j=0;j<m;j++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if((best_cost[mp(a,b)] == 0)||(best_cost[mp(a,b)] > c))
            {
                best_cost[mp(a,b)] = c;
            }
        }
        for(auto & it : best_cost)
        {
            int a = it.first.first;
            int b = it.first.second;
            int c = it.second;
            G[a].push_back(mp(c,b));
            G[b].push_back(mp(c,a));
        }
        scanf("%d",&src);
        int max_distance[n];
        bool visited[n];
        for(int l = 0;l<n;l++)
        {
            visited[l] = false;
            max_distance[l] = INF;
        }
        dijkstra(G,max_distance,src);
        printf("Case %d:\n",i+1);
        for(int j = 0;j<n;j++)
        {
            if(max_distance[j]!=INF)
            {
                printf("%d\n",max_distance[j]);
            }
            else
            {
                printf("Impossible\n");
            }
        }

    }
}