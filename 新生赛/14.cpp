#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define INF 0
int map[102][102];
int dis[102];
int vis[102];
int n; 
int ans;
void prim(){
	int i,j;
	
	memset(vis,0,sizeof(vis));
	for(i=1;i<n;i++)
		dis[i]=INF;
	dis[0]=0;
	for(i=0;i<n;i++){
		int index=-1,min=INF;
		for(j=1;j<n;j++){
			if(!vis[j]&&dis[j]>min){
				min=dis[j];
				index=j;
			}
		}
		vis[index]=1;
		ans+=dis[index];
		for(j=0;j<n;j++){
			if(!vis[j])
			dis[j]=dis[j]<map[index][j]?map[index][j]:dis[j];
		}
	}
}
int main(){
	int i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&map[i][j]);
				
			}
		}
		ans=0;
		prim();
		printf("%d\n",ans);
	}
}

