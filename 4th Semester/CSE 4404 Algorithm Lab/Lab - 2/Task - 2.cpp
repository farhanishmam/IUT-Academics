#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define lld long long int
#define INF 1e6

struct Edge
{
    int start;
    int end;
    int weight;
};

bool bellman_ford(Edge *e, int dist[], int n, int m)
{
    dist[e[0].start] = 0;
    for (int i =0; i < n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = e[j].start;
            int v = e[j].end;
            int weight = e[j].weight;
            int cost = dist[u] + weight;
            if (dist[u] < INF && cost < dist[v])
                dist[v] = cost;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u = e[i].start;
        int v = e[i].end;
        int weight = e[i].weight;
        if (dist[u] < INF && dist[u] + weight < dist[v])
            return true;
    }
    return false;
}

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int n,m;
        cin>>n>>m;
        Edge edge[m];
        int dist[n];
        for(int j=0;j<n;j++)
        {
            dist[j] = INF;
        }
        for(int j=0;j<m;j++)
        {
            cin >> edge[j].start>> edge[j].end>> edge[j].weight;
        }
        if(bellman_ford(edge,dist,n,m)) cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
    }
}