#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

const int MAXN=110;
int uN,vN;
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    int v;
    for(v=0;v<vN;v++)
      if(g[u][v]&&!used[v])
      {
          used[v]=true;
          if(linker[v]==-1||dfs(linker[v]))
          {
              linker[v]=u;
              return true;
          }
      }
    return false;
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}

int main()
{
    int k;
    int i,u,v;
    while(scanf("%d",&uN),uN)
    {
        scanf("%d%d",&vN,&k);
        memset(g,0,sizeof(g));
        while(k--)
        {
            scanf("%d%d%d",&i,&u,&v);
            if(u>0&&v>0)g[u][v]=1;
        }
        printf("%d\n",hungary());
    }
    return 0;
}
