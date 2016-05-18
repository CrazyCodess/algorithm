#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[110][110];
int used[110];
int link[110];
int k,n,m;
bool dfs(int u){
	int v;
	for(v=0;v<m;v++){
		if(g[u][v]&&!used[v]){
			used[v]=1;
			if(link[v]==-1||dfs(link[v]))
			{
				link[v]=u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int i,u,v;
	int res;
	while(scanf("%d",&n),n){
		scanf("%d%d",&m,&k);
		memset(g,0,sizeof(g));
		while(k--){
			scanf("%d%d%d",&i,&u,&v);
			if(u>0&&v>0)g[u][v]=1;
			
		}
		res=0;
		memset(link,-1,sizeof(link));
		for(u=0;u<n;u++){
			memset(used,0,sizeof(used));
			if(dfs(u))res++;
		}
		printf("%d\n",res);
	}
	return 0;
} 
