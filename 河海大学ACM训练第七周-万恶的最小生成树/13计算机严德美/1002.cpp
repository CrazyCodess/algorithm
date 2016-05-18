/*
poj2377Bad Cowtractors
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 999999999;
int map[1002][1002];
int dis[1002];
int vis[1002];
int n;
int ans;
void prim(){
	int i,j;
	ans=0;
	for(i=1;i<=n;i++)
		dis[i]=-1;
		memset(vis,0,sizeof(vis));
	dis[1]=0;
	for(i=1;i<=n;i++){
		int index=-1,min=-1;
		for(j=1;j<=n;j++){
			if(!vis[j]&&dis[j]>min){
				min=dis[j];
				index=j;
			}
		}
		vis[index]=1;
		ans+=dis[index];
		for(j=1;j<=n;j++){
			if(!vis[j]){
				dis[j]=dis[j]<map[index][j]?map[index][j]:dis[j];
			}
		}
	}
}
int main(){
	int m,i,j,a,b,c;
	while(cin>>n&&cin>>m){
		memset(map,999999999,sizeof(map));
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&a,&b,&c);
			map[a][b]=map[b][a]=c;
		}
		prim();
		if(ans>999999999)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
} 