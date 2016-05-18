#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const double MIN=0.0; 
struct Edge{
	int u,v;
	double r,c;
};
Edge edge[205];
double dist[105],v;
int n,m,s,e;
void init(int u,int v,double r,double c){
	edge[e].u=u;
	edge[e].v=v;
	edge[e].r=r;
	edge[e].c=c;
	e++;
}

bool Bellman_Ford(){
	int i,j;
	memset(dist,MIN,sizeof(dist));
	dist[s]=v;
	for(i=1;i<=n-1;i++){
		bool flag=false;
		for(j=1;j<=e;j++){
			if(dist[edge[j].v]<(dist[edge[j].u]-edge[j].c)*edge[j].r){
				dist[edge[j].v]=(dist[edge[j].u]-edge[j].c)*edge[j].r;
				flag=true;
			}
				
		}
		if(dist[s]>v)return true;
		//printf("--dist--\n");
		if(!flag)return false;
		
	}
	//printf("--dist--\n");
	for(j=1;j<=e;j++){
		if(dist[edge[j].v]<(dist[edge[j].u]-edge[j].c)*edge[j].r){
			dist[edge[j].v]=(dist[edge[j].u]-edge[j].c)*edge[j].r;
			return true;
		}
				
	}
	if(dist[s]>v)return true;
	//printf("----\n");
	return false;
}

int main(){
	double r1,c1,r2,c2;
	int i,j,a,b;
	
		scanf("%d%d%d%lf",&n,&m,&s,&v);
		e=1;
		for(i=1;i<=m;i++){
			scanf("%d%d%lf%lf%lf%lf",&a,&b,&r1,&c1,&r2,&c2);
			init(a,b,r1,c1);
			init(b,a,r2,c2);
		}
		if(Bellman_Ford())printf("YES\n");
		else printf("NO\n");
		
	return 0;
} 
