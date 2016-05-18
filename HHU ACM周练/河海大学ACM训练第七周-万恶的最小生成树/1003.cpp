#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define INF 999999999;
struct nod{
	int x;
	int y;
};
int num[52][52];
int node[102][102];
char map[52][52];
int vis[52][52];
int dis[52][52];
int front=0,rear=1;
int m,n;
int dir[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
int t;
int num1;
int n0;
void init(int x,int y){
	
	int i,j;
	char c;
	for(i=1;i<=y;i++){
		for(j=1;j<=x;){
			if((c=getchar())!='\n'){
				map[i][j]=c;
				j++; 
			}
			//gets(map[i]);
		}
	}
}

void  bfs(int x1,int y1){	
	queue<nod> q;
	int x,y;
	memset(vis,0,sizeof(vis));
	vis[x1][y1]=1;
	nod n1={x1,y1};
	q.push(n1);
	dis[x1][y1]=0;
	while(!q.empty()){
		nod n2=q.front();q.pop();
		x=n2.x;
		y=n2.y;
		if(num[x][y]!=-1)node[num[x1][y1]][num[x][y]]=dis[x][y];
		int u;
		for(u=0;u<4;u++){
			int dx=x+dir[u][0];
			int dy=y+dir[u][1];
			if(dx<0||dy<0||dx>m||dy>n||vis[dx][dy]==1||map[dx][dy]=='#')
				continue;
		 	vis[dx][dy]=1;
		 	dis[dx][dy]=dis[x][y]+1;
		 	q.push((nod){dx,dy});
		}
	}
}
int prim(){
/*	 int d[110], ans = 0;
    bool v[110];

    memset(v, false, sizeof(v));

    for(int i=1; i<=num1; i++) {
        d[i] = node[n0][i];
    }

    v[n0] = true;
    d[n0] = 0;

    for(int i=1; i<=num1; i++) {
        int x, m=INF;
        for(int y=1; y<=num1; y++) if(!v[y] && m >= d[y]) m = d[x=y];
        v[x] = true;
        ans += m;
        for(int y=1; y<=num1; y++) if(!v[y] && d[y] > node[x][y]) d[y] = node[x][y];
    }
	*/
 	int ans=0;
	int i,j;
	int vi[102];
	int di[102];
	memset(vi,0,sizeof(vi));
	for(i=1;i<=num1;i++)
		di[i]=INF;
	di[1]=0;
	vi[1]=1;
	for(i=1;i<=num1;i++){
		int index=-1,min=INF;
		for(j=1;j<=num1;j++){
			if(!vi[i]&&di[j]>min){
				min=di[j];
				index=j;
			}
		}
		vi[index]=1;
		ans+=di[index];
		for(j=1;j<=num1;j++){
			if(!vi[j])
			di[j]=di[j]>node[index][j]?node[index][j]:di[j];
		}
	}
	return ans;
}
/*
void print(int x,int y){
		int i,j;
	for(i=1;i<=y;i++){
		for(j=1;j<=x;j++){
			printf("%c",map[i][j]);
			
		}
		printf("\n");
	}
}*/
int main(){
	int i,j;
	while(scanf("%d",&t)!=0){
		while(t--){
			memset(map,'0',sizeof(map));
			scanf("%d%d",&m,&n);
			init(m,n);
			num1=1;
			memset(num,-1,sizeof(num));
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(map[i][j]=='A'||map[i][j]=='S'){
						num[i][j]=num1++;
					}
					if(map[i][j]=='S')n0=num1-1;
				}
			}
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(map[i][j]=='A'||map[i][j]=='S'){
						bfs(i,j);
					}
				}
			}
			for(i=1;i<=num1;i++){
				for(j=1;j<=num1;j++)
					printf("%d",node[i][j]);
					printf("\n");
			}
			printf("%d\n",prim());
			//print(x,y);
		}
	}
	return 0;
} 