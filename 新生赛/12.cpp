#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int v[1002][1002];
int main(){
	int n;
	int sx,sy,tx,ty;
	int i,j;
	int a,b,c
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d%d",&v[i][0],&v[i][1]);
			
		}
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		a=ty-sy;
		b=-(tx-sx);
		c=tx*sy-sx*ty;
	}
	return 0;
}
