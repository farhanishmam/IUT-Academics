#include <bits/stdc++.h>
using namespace std;

bool visited[50000];
int adj_list[50000];
int distancee[50000];

int dfs(int src)
{
    visited[src]=true;
    int d = 0;
    int top = adj_list[src];
    if(!visited[top])  //****if it goes back to a visited node that means it's a loop. Then the distance is stored
    {
        d = dfs(top); //assigned distance to the parent node
    }
    visited[src] = false;
    distancee[src] = d;
    return d+1; //to assign the distance to the parent
}

int visit_all(int n)
{
    int max_value = -1;
    int max_node;
    for(int i=0;i<n;i++) //dfs on all nodes
    {
        if(distancee[i]==-1)
        {
            dfs(i);
        }
        if(distancee[i]>max_value)
        {
            max_value = distancee[i];
            max_node = i;
        }

    }
    /*
    for(int i=0;i<n;i++)
    {
        cout<<distancee[i]<<" ";
    }
    cout<<endl;
     */
    return max_node+1;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        memset(visited, false, sizeof(visited));
        memset(distancee, -1, sizeof(distancee));
        memset(adj_list, -1, sizeof(adj_list));
        for(int j=0;j<n;j++)
        {
            int a,b;
            cin>>a>>b;
            adj_list[a-1] = b-1;
        }
        printf("Case %d: %d\n", i+1, visit_all(n));
        //cout<<visit_all(n)<<endl;
    }
}