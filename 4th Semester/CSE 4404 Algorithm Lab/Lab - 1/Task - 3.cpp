#include<bits/stdc++.h>

using namespace std;

int no = 0;
int county = 0;
int G[25][25];
bool vis [25][25];

void dfs(int sx, int sy)
{
    if(sx < 0 || sy < 0 || sx>=25 || sy>=25)
        return;
    if(vis[sx][sy] || G[sx][sy] == 0)
        return;
    vis[sx][sy] = true;
    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            dfs(sx + i, sy + j);
        }
    }
}


void visitAll ()
{
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            if(!vis[i][j] && G[i][j] == 1)
            {
                county++;
                dfs(i,j);
            }
        }
    }
    printf("Image number %d contains %d war eagles.\n",no,county);
    county = 0;
    return;
}

int main(void)
{
    memset(vis, false, sizeof(vis));
    memset(G, 0, sizeof(G));
    string line;
    int a=0;
    while (getline(cin, line))
    {
        //case-1 when dimension is 1
        if(line.size() == 1 && line[0]=='1')
        {
            string s;
            getline(cin,s);
            if(s[0]=='0')
            {
                no++;
                printf("Image number %d contains 0 war eagles.\n",no);
            }
            else
            {
                no++;
                printf("Image number %d contains 1 war eagles.\n",no);
            }
            continue;
        }
        //case-2 when dimension is 2
        if(line.size() == 1 && line[0]=='2')
        {
            no++;
            string s1,s2;
            getline(cin,s1);
            getline(cin,s2);
            if(s1=="00"&& s2=="00")
            {
                printf("Image number %d contains 0 war eagles.\n",no);
            }
            else printf("Image number %d contains 1 war eagles.\n",no);
            continue;
        }
        //case-3 when dimension is another number
        if((line.size()==1||line.size()==2)&&(a==0))
        {
            //single digit dimension
            if(line.size()==1) { a = line[0] - '0' - 1; }
            else //multi digit dimension
            {
                a = line[1] - '0' - 1;
                a += (line[0] - '0')*10;
            }
            no++;
            continue;
        }
        if(a>=0)
        {
            for(int i=0;i<line.size();i++)
            {
                if(line[i]=='1')
                    G[a][i] = 1;
            }
            a--;
        }
        if(a==-1)
        {
            visitAll();
            memset(vis, false, sizeof(vis));
            memset(G, 0, sizeof(G));
            a = 0;
        }
    }
    return 0;
}