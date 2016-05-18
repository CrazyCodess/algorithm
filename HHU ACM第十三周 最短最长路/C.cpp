#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Edge{
	int v,w,next;
};
Edge edge[1000005];
int pre[100005];
ll d[100005]; 
int n,m,top,head[1000005];
bool vis[1000005];
void init(){
	int i;
	
	for(i=1;i<=n;i++){
		pre[i]=i;
	}	
	memset(vis,false,sizeof(vis));
	top=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int u,int v,int w){
	edge[top].v=v;
	edge[top].w=w;
	edge[top].next=head[u];
	head[u]=top++;
} 
void dfs(int pre,int u){
	vis[u]=true;
	for(int i=head[u];~i;i=edge[i].next){
		
		int v=edge[i].v;
	
			if(v==pre)continue;
			//if(vis[v])return;
			d[v]=d[u]+edge[i].w;
			dfs(u,v);
			//vis[v]=false;			
		

	} 
	return;
}
int find(int x){
	if(x!=pre[x]){
		pre[x]=find(pre[x]);
	}
	return pre[x];
} 
void Un(int a,int b){
	pre[b]=a;
	//num[a]+=wi;
	return;
}


int main(){
	int i,j,flag,u,v,w;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		flag=false;
		for(i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&w);	
			int fx=find(u);
			int fy=find(v);
			addEdge(u,v,w);
			addEdge(v,u,w);
			if( fx != fy ){
				Un(fx,fy);
			}
			else{
				flag=true;
				break;
			} 
			
			
			
		}
		ll ans=0;
		if(flag)printf("YES\n");
		else{
			dfs(0,u);
			ans=max(ans,*max_element(d+1,d+1+n));
			printf("%lld\n",ans);
		}
		
	}
	return 0;
}
