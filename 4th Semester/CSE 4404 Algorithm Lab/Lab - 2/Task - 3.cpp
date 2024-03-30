#include <bits/stdc++.h>
#define pii pair<int, int>
#define inf 0x3f3f3f3f

using namespace std;

vector<pii> adjList[100001];
bool visited[100001];
int dist[100001];
int flag[100001]={0};

priority_queue<pii,vector<pii>,greater<pii>> pq;
int result = 0;

void dijkstra()
{
    while(!pq.empty())
    {
        int u = pq.top().second;
        int cost_u=pq.top().first;
        pq.pop();

        if(visited[u]==true)
            continue;

        visited[u] = true;
        int len = adjList[u].size();
        for (int i=0;i<len;i++)
        {
            int v = adjList[u][i].second;
            int cost_v=adjList[u][i].first;

            if(dist[v] >= dist[u]+cost_v)
            {
                if(flag[v] == 0 && dist[v] !=inf) //so that result is increased the first time it is relaxed
                    result++;
                flag[v] = 1;
                dist[v] = dist[u]+cost_v;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {

    int n,m,k;
    cin>>n>>m>>k;
    while(m--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adjList[u].push_back({w,v});
        adjList[v].push_back({w,u});
    }

    memset(visited,false,sizeof(visited));
    memset(dist,inf,sizeof(dist));

    for(int i = 1; i <= k; ++i)
    {
        int v, w;
        cin>>v>>w;

        if(dist[v] !=inf) //if there are multiple weights for the same destination
            result++;
        dist[v] = min(dist[v], w);
    }
    dist[1] = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(dist[i] !=inf)
            pq.push({dist[i], i});
    }
    dijkstra();
    cout<<result;
    return 0;
}