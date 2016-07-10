#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int const INF = 0x3fffffff;  
int map[555][555],path[555],pathnum[555],val[555],totval[555],dis[555];
bool vis[555];
int  n,m,s,d;
int p[555];
void dijkstra(int v){
	int i,j;
	for ( i = 0; i < n; ++i)
	{
		dis[i]=INF;
	}
	vis[v]=true;
	dis[v]=0;
	totval[v]=val[v];
	pathnum[v]=1;
	for ( i = 0; i <n ; ++i)
	{
		if(map[v][i]<INF&&i!=v){
			dis[i]=map[v][i];
			path[i]=v; 		//保存最短路径上的前一个节点
			totval[i]=val[v]+val[i];
			pathnum[i]=1;
		}
	}
	int min,u;
	for ( i = 0; i < n-1; ++i)
	{
		min=INF;
		u=v;
		for ( j = 0; j < n; ++j)
		{
			if(!vis[j]&&dis[j]<min){
				min=dis[j];
				u=j;
			}
		}
		vis[u]=true;
		for ( j = 0; j < n; ++j)
		{
			if(dis[j]>dis[u]+map[u][j]){
				dis[j]=dis[u]+map[u][j];
				path[j]=u;
				pathnum[j]=pathnum[u];
				totval[j]=totval[u]+val[j];
			}
			else if(dis[u]+map[u][j]==dis[j]){
				pathnum[j]=pathnum[j]+pathnum[u];
				if(totval[j]<totval[u]+val[j]){
					totval[j]=totval[u]+val[j];
					path[j]=u;
				}
			}
		}
	}

}
int main(){
	int i,j,a,b,l;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&val[i]);
	}
	for ( i = 0; i < n; ++i)
	{
		for ( j = 0; j < n; ++j)
		{
			map[i][j]=INF;
		}
	}
	for ( i = 0; i < m; ++i)
	{
		scanf("%d%d%d",&a,&b,&l);
		map[a][b]=l;
		map[b][a]=l;

	}
	dijkstra(s);
	int num=0,des=d;
	while(des!=s){
		p[num]=des;
		des=path[des];
		num++;
	}
	p[num]=s;
	printf("%d %d\n", pathnum[d],totval[d]);
	for ( i = num; i >0; i--)
	{
		printf("%d ", p[i]);
	}
	printf("%d\n",p[0] );




	return 0;
}