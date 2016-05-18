#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[1000][1000];
int used[1000];
int link[1000];
int n;
bool dfs(int u){
	int v;
	for(v=0;v<n;v++){
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
	int u,v;
	int i,j,k;
	int res;
	while(scanf("%d",&n)!=EOF){
		memset(g,0,sizeof(g));
		res=0;
		for(k=0;k<n;k++){
			scanf("%d: (%d)",&u,&j);
				for(i=1;i<=j;i++){
					scanf("%d",&v);
					g[u][v]=1;
				}
		}
		memset(link,-1,sizeof(link));
		for(u=0;u<n;u++){
			memset(used,0,sizeof(used));
			if(dfs(u))res++;
		}
		
		printf("%d\n",n-res/2); 
	}
	return 0;	
}
