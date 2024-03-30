#include<bits/stdc++.h>
#define psi pair<string,int>
using namespace std;

map<string, vector<psi> > adjList;
vector<string> city_names;
map<string, long long> dist;
vector<long long> total_cost;
int n;

void bellman()
{
    dist["Calgary"] = 0;

    for(int k=1; k<n;k++)
    {
        for(int i=n-2;i>=0;i--)
        {
            string u=city_names[i];
            int len = adjList[u].size();

            for(int j = 0; j <len; ++j)
            {
                string v=adjList[u][j].first;
                long long int cost_v=adjList[u][j].second;

                if(dist[v] > dist[u] + cost_v)
                    dist[v] = dist[u] + cost_v;
            }
        }

        total_cost.push_back(dist["Fredericton"]);
    }
}

int main()
{
    int t;
    cin>>t;

    for(int z=1;z<=t;z++)
    {
        adjList.clear();
        city_names.clear();
        dist.clear();
        total_cost.clear();

        cin >> n;
        string city;

        for(int i = 0; i < n; ++i)
        {
            cin >> city;
            city_names.push_back(city);
            dist[city] = INT_MAX;
        }

        int m, cost;
        cin >> m;

        string city2;

        while(m--)
        {
            cin >> city >> city2 >> cost;
            adjList[city].push_back({city2,cost});
        }

        bellman();

        int q;
        cin >> q;

        cout << "Scenario #" << z <<endl;

        while(q--)
        {
            int st;
            cin>>st;

            if(st>=n-2)
                st=n-2;

            if(total_cost[st]==INT_MAX)
                cout<<"No satisfactory flights"<<endl;

            else
                cout << "Total cost of flight(s) is $"<<total_cost[st]<<endl;
        }

        if(z!= t)
            cout <<endl;
    }

    return 0;
}