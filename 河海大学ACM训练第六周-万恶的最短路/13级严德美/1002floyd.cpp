/*
求出任意两点之间要转换的开关，赋值给map[i][j]
然后输出mapp[a][b] 
*/
#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 999;
int map[101][101];
int n;
void floyd(){
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(map[i][j]>(map[i][k]+map[k][j]))
					map[i][j]=map[i][k]+map[k][j];
			}
		}
}
void init(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			map[i][j]=MAX;
}
int main(){
	int a,b,i,j,num,k;
	while(scanf("%d%d%d",&n,&a,&b)!=EOF){
		init();
		for(i=1;i<=n;i++){
			scanf("%d",&num);
			for(j=1;j<=num;j++){
				scanf("%d",&k);
				if(j==1)map[i][k]=0;
				else map[i][k]=1;
			}
		}
		floyd();
		if(map[a][b]>=999)printf("-1\n");
		else printf("%d\n",map[a][b]);		
	}
return 0;
}