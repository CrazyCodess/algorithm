#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
char maze[7][7];
int vis[7][7];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m;
//int bx,by
struct Node{
	int x;
	int y;
	int step;
	Node(int x1,int y1,int step1):x(x1),y(y1),step(step1){}
	
}; 
bool bfs(int x,int y,int step){
	int i;
	Node node(x,y,0);
	queue<Node> q;
	while(!q.empty())q.pop();
	q.push(node);
	while(!q.empty()){
		node=q.front();
		q.pop();
		if(maze[node.x][node.y]=='D'&&node.step==step)
			return true;
		vis[node.x][node.y]=1;
		for(i=0;i<4;i++){
			int x=node.x+dir[i][0];
			int y=node.y+dir[i][1];
			if(x>=0&&y>=0&&x<n&&y<m&&maze[x][y]!='X'&&vis[x][y]==0){
				vis[x][y]=1;
				Node next(x,y,node.step+1);
				q.push(next);
			}
		}
	}
	return false;
}
int main(){
	int t;
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
							
			}			
		}				
		memset(vis,0,sizeof(vis));
		if(bfs(ax,ay,t))printf("YES\n");
		else printf("NO\n");
		
	} 
	return 0;
}
