#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
char map[105][105];
int cnt;
struct node{
	int x;
	int y;
	int pre;
}edge[10005];
int front=0,rear=1;
int vis[105][105];
int dir[8][2]={ 1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
void find(int i){
	if(edge[i].pre!=-1){
		find(edge[i].pre);
		cnt++;
	}
}
void bfs(int x1,int y1){
	cnt=0;
	edge[front].x=x1;
	edge[front].y=y1;
	edge[front].pre=-1;
	while(front<rear){
		int u;
		for(u=0;u<8;u++){
			int x=edge[front].x+dir[u][0];
			int y=edge[front].y+dir[u][1];
			int nx=edge[front].x+dir[u][0]/2;
			int ny=edge[front].y+dir[u][1]/2;
			if(x<0||y<0||x>=n||y>=m||vis[x][y]==1||map[nx][ny]=='#'||map[x][y]=='#'){
				
				continue;
				
			}
				
			else{
				vis[x][y]=1;
				edge[rear].x=x;
				edge[rear].y=y;
				edge[rear].pre=front;
				rear++;
				
			}
			if(map[x][y]=='e')
			{
				cnt++; 
				find(front);
					
			}
		}
		front++;
	}
}
int main(){
	int i,j,x1,y1;
	char s;
	while(scanf("%d%d",&n,&m)!=EOF){
		front=0;
		rear=1;
		memset(vis,0,sizeof(vis));
		memset(map,'\0',sizeof(map));
		//ans=0;
		
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				cin>>s;
				map[i][j]=s;
				if(s=='s'){
					x1=i;
					y1=j;
				}
			}
		cnt=0;
		bfs(x1,y1);
		
		if(cnt!=0)
			printf("%d\n",cnt);
		else printf("-1\n");
	}
	return 0;
} 
