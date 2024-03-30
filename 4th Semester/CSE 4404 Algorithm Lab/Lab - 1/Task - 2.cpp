#include <bits/stdc++.h>
#define nodeCount 64
using namespace std;

bool check(pair<int,int> a) //checks validity of an input 
{
    return (a.first >= 0 && a.first <= 7) && (a.second >= 0 && a.second <= 7);
}


int bfs (pair<int,int> src, pair<int, int> dest)
{
    if(src == dest)
    {
        return 0;
    }
    bool visited[8][8];
    int level [8][8];
    //pair<int,int> parent[8][8];
    queue <pair<int, int>> q;

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    //memset(parent, NULL, sizeof(parent));

    vector<pair<int, int>> list[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            pair<int, int> p[8];
            p[0] = make_pair(i+2,j+1);
            p[1] = make_pair(i+2,j-1);
            p[2] = make_pair(i-2,j+1);
            p[3] = make_pair(i-2,j-1);
            p[4] = make_pair(i+1,j+2);
            p[5] = make_pair(i+1,j-2);
            p[6] = make_pair(i-1,j+2);
            p[7] = make_pair(i-1,j-2);
            for(int k=0;k<8;k++)
            {
                if(check(p[k])) list[i][j].push_back(p[k]);
            }
        }
    }

    q.push(src);
    visited[src.first][src.second] = true ;
    level[src.first][src.second] = 0;
    //parent[src.first][src.second] = NULL;
    while (!q. empty ())
    {
        pair<int,int> u = q.front();
        q.pop ();
        for (pair<int,int> v : list[u.first][u.second])
        {
            if (! visited[v.first][v.second])
            {
                visited[v.first][v.second] = true ;
                level[v.first][v.second] = level[u.first][u.second] + 1;
                if(v == dest)
                {
                     return level[v.first][v.second];
                }
                q.push (v);
            }
        }
    }
}

int main(void)
{
    string line;
    while (getline(cin, line))
    {
        pair<int,int> src,dst;

        src.first = line[1] - '0' - 1;
        src.second = line[0] - 'a';
        dst.first = line[4] - '0' -1;
        dst.second = line[3] - 'a';
        printf("To get from %c%c to %c%c takes %d knight moves.\n",line[0],line[1],line[3],line[4],bfs(src,dst));
        //cout<<src.first<<" "<<src.second<<endl;
        //cout<<dst.first<<" "<<dst.second<<endl;
    }
}