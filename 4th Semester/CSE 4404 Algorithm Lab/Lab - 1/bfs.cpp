// Here , nodeCount denotes the total number of nodes in our graph
vector <int>G[nodeCount]; // stores the adjacent list
int level [nodeCount];
int parent [nodeCount];
bool vis [nodeCount];

void bfs (int src)
{
    queue <int>q;
    q.push(src);
    vis [ src ] = true ;
    level [ src ] = 0;
    parent [ src ] = -1;
    while (!q. empty ())
    {
        int u = q. front ();
        q. pop ();
        for (v : G[u])
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
}
