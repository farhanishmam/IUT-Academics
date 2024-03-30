// Here , nodeCount denotes the total number of nodes in our graph
// V stores all the vertices
vector <int >G[ nodeCount ]; // stores the adjacent list
int parent [ nodeCount ];
bool vis [ nodeCount ];
void dfs ( int src )
{
    for (v : G[src ])
    {
        if (! vis[v])
        {
            vis [v] = true ;
            parent [v] = src ;
            dfs (v);
        }
    }
}

void visitAll ()
{
    for ( src : V)
    {
        if (! vis[ src ])
        {
            parent [src ] = -1;
            dfs ( src );
        }
    }
}
