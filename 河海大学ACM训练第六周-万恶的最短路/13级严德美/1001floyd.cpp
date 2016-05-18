/*
求出任意两点间最大距离，赋值给map[i][j]
最后输出map[a][b] 
*/ 
#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 999999999;
int map[301][301];
int n;
void floyd(){
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(map[i][k]<map[i][j]&&map[k][j]<map[i][j]){
					map[i][j]=map[i][k]>map[k][j]?map[i][k]:map[k][j];
				}
			}
		}
}
int main(){
	int m,t,i,j,s,e,h,a,b;
	while(scanf("%d%d%d",&n,&m,&t)!=EOF){
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				map[i][j]=MAX;
			}
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&s,&e,&h);
			map[s][e]=h;
		}
		floyd();
		for(i=0;i<t;i++){
			scanf("%d%d",&a,&b);
			if(map[a][b]>=999999999)printf("-1\n");
			else 
			printf("%d\n",map[a][b]);
		}
	}
	return 0;
} 