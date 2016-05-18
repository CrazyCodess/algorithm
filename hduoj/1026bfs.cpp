#include<iostream>
#include<queue>
#include<stdio.h>
#include<ctype.h>
#include<queue>
#include<stack>
#include<limits.h>
#include<string.h>
using namespace std;
struct Node{
	char c;
	int x;
	int y;
	int prex;
	int prey;
	int time;
	 bool operator<(const Node&a)const
    {
        return a.time<time;
    }
}maze[105][105];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int flag;
Node node;
int n,m;
int bfs(){
	int i;
	int x1,y1;
	maze[0][0].time=0;
	priority_queue<Node> q;
	while(!q.empty())q.pop();
	q.push(maze[0][0]);
	while(!q.empty()){
		node=q.top();
		q.pop();
		if(node.x==n-1&&node.y==m-1)
			return 1;
		for(i=0;i<4;i++){
			x1=node.x+dir[i][0];
			y1=node.y+dir[i][1];
			if(x1>=0&&x1<n&&y1>=0&&y1<m){
				if(maze[x1][y1].c=='.'&&node.time+1<maze[x1][y1].time){
					maze[x1][y1].prex=node.x;
					maze[x1][y1].prey=node.y;
					maze[x1][y1].time=node.time+1;
					q.push(maze[x1][y1]);
				}
				else if(isdigit(maze[x1][y1].c)&&node.time+maze[x1][y1].c-'0'<maze[x1][y1].time){
					maze[x1][y1].prex=node.x;
					maze[x1][y1].prey=node.y;
					maze[x1][y1].time=node.time+maze[x1][y1].c-'0'+1;
					q.push(maze[x1][y1]);					
				}
			}
		}
		
	} 
	
	return 0;
}
void printPath(int x,int y){
	int i;
	if(x==0&&y==0)return;
	int prex=maze[x][y].prex;
	int prey=maze[x][y].prey;
	printPath(prex,prey);
	int prel=maze[prex][prey].time;
	int l=maze[x][y].time;
	printf("%ds:(%d,%d)->(%d,%d)\n",prel+1,prex,prey,x,y);
	for(i=prel+2;i<=l;i++){
		printf("%ds:FIGHT AT (%d,%d)\n",i,x,y);
	}
}
int main(){
	int i,j;
	while(scanf("%d %d",&n,&m)!=EOF){
		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>maze[i][j].c;
				maze[i][j].x=i;
				maze[i][j].y=j;
				maze[i][j].time=INT_MAX;
			}
			
		}
		flag=bfs();
		if(!flag){
			 printf("God please help our poor hero.\n");
            printf("FINISH\n");
			continue;
		}
		printf("It takes %d seconds to reach the target position, let me show you the way.\n",maze[n-1][m-1].time);
        printPath(n-1,m-1);
        printf("FINISH\n");
		
	}
	return 0;
}
