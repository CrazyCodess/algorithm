#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
char map[105][105];
int sx,sy,ex,ey;
int n,m;
int vis[105][105];
int dir[8][2]={ 1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
struct node{
	int x,y;
	int dis;
};
void bfs(){
	memset(vis,0,sizeof(vis));
	queue<node> q;
	//int i;
	node nod={sx,sy,0};
	q.push(nod);
	bool mark=false;
	while(!q.empty()){
		node u=q.front();
		q.pop();
		if(u.x==ex&&u.y==ey){
			if(u.dis==0)break;
			printf("%d\n",u.dis);
			mark=true;
			break;
		}
		node v;
		for(int i=0;i<8;i++){
			v.x=u.x+dir[i][0];
			v.y=u.y+dir[i][1];
			int nx=u.x+dir[i][0]/2;
			int ny=u.y+dir[i][1]/2;
			if(map[nx][ny]=='#'||vis[v.x][v.y]==1||map[v.x][v.y]=='#'||v.x<0||v.y<0||v.x>=n||v.y>=m)
				continue;
			else{
				v.dis=u.dis+1;
				vis[v.x][v.y]=1;
				q.push(v);
				
			}
		}
		
	}
	if(!mark)printf("-1\n");
	return;
}
int main(){
	int i,j;
	char c;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				cin>>c;
				map[i][j]=c;
				if(c=='s'){
					sx=i;
					sy=j;
				}
				else if(c=='e'){
					ex=i;
					ey=j;
				}
			}
		bfs(); 
	}
	return 0;
}
