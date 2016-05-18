#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Edge{
	int u,v,w;
};
Edge edge[1000005];
int pre[100005];
int we[100005];
int f[100005]; 
int n,m;
int find(int x){
	int r=x;
	while(pre[r]!=r)
		r=pre[r];
	int p;
	p=x;
	while(p!=r){
		pre[p]=r;
		
		p=pre[p];
	}
	return r;
} 


void Un(int a,int b,int wi){
	pre[a]=find(a);
	pre[b]=find(a);
	we[find(a)]+=wi;
	return;
}


int main(){
	int i,j,flag;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=1;i<=n;i++){
			pre[i]=i;
		}
		memset(we,0,sizeof(we));
		flag=false;
		for(i=0;i<m;i++){
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);	
			
			if( find(edge[i].u) != find(edge[i].v) ){
				Un(edge[i].u,edge[i].v,edge[i].w);
			}
			else flag=true;
		}
		int ans=0;
		if(flag)printf("YES\n");
		else{
			for(i=1;i<=n;i++)if(ans<we[i])ans=we[i];
			printf("%d\n",ans);
		}
		
	}
	return 0;
}
