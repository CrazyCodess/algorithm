#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
char maze[7][7];
int vis[7][7];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,flag,bx,by,t;
void dfs(int x,int y,int step){
	int i,mx,my;
	if(x==bx&&y==by){
		if(step==t)
		flag=1;
		return;
	}
	if(step>=t)return;
	for(i=0;i<4;i++){
		mx=x+dir[i][0];
		my=y+dir[i][1];
		if(maze[mx][my]!='X'&&mx>=0&&my>=0&&mx<n&&my<m&&!vis[mx][my]){
			vis[mx][my]=1;
			dfs(mx,my,step+1);
			vis[mx][my]=0;
			if(flag)return;
		}	
	}
}

int main(){

	int i,j,ax,ay;
	while(scanf("%d%d%d",&n,&m,&t)!=EOF&&(n+m+t)){
		for(i=0;i<n;i++){
			getchar();
			for(j=0;j<m;j++){
				
				scanf("%c",&maze[i][j]);
				if(maze[i][j]=='S'){
					ax=i;
					ay=j;
				}	
				if(maze[i][j]=='D'){
					bx=i;
					by=j;
				}			
			}			
		}			
		getchar();	
		if(abs(ax-bx)+abs(ay-by)>t||(int)(abs(ax-bx)+abs(ay-by)+t)%2!=0){
			
			printf("NO\n");
			continue;
		}
		memset(vis,0,sizeof(vis));
		vis[ax][ay]=1;
		flag=0;
		dfs(ax,ay,0);
		
		
		if(flag)printf("YES\n");
		else printf("NO\n");
		
	} 
	return 0;
}
