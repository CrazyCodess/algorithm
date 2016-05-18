#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[122][122];
int used[122];
int link[122];
int n;
bool dfs(int u){
	int v;
	for(v=1;v<=n;v++){
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
	int t,e,u,v,res;
	int i,j,k,start,end;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%d%d",&n,&e);
		memset(g,0,sizeof(g));
		for(i=1;i<=e;i++){
			scanf("%d%d",&start,&end);
			g[start][end]=1;
			
		}
		res=0;
		memset(link,-1,sizeof(link));
		for(u=1;u<=n;u++){
			memset(used,0,sizeof(used));
			if(dfs(u))res++;
		}
		printf("%d\n",n-res);
		
	}	
	return 0;
} 
