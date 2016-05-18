#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 99999999
int map[105][105];
int ans,n,m; 
int dijstra(){
	int dist[105],vis[105],i,j,v,min;
	//memset(dist,MAX,sizeof(dist));
	//memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++){
		vis[i]=0;
		dist[i]=map[1][i];
		//printf("dist=%d\n",dist[i]);
	}
	vis[1]=1;
	for(i=1;i<n;i++){
		min=MAX;
		
		for(j=1;j<=n;j++){
			if(!vis[j]){
				if(min>dist[j]){
					min=dist[j];
					v=j;
				}
			}
		}
		vis[v]=1;
		for(j=1;j<=n;j++){
			if(!vis[j]&&(min+map[v][j])<dist[j]){
				dist[j]=min+map[v][j];
			}
		}
	}
	ans=0;
	ans=dist[n];
	return ans;
	
}
int main(){
	int i,j,row,col,value;
	while(scanf("%d%d",&n,&m)!=EOF){
		//memset(map,MAX,sizeof(map));
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				map[i][j]=99999999;
		if(n==0&&m==0)break;
		
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&row,&col,&value);
			map[row][col]=value;
			map[col][row]=value;
		}
		printf("%d\n",dijstra());
		
	}
	return 0;
} 
