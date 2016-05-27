#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int l;
	int w;
}mac[5005];
int dp[5005];
int vis[5005];
bool cmp(const node &ele1,const node &ele2){
	if(ele1.l<ele2.l)return true;
	if(ele1.l==ele2.l){
		if(ele1.w<ele2.w)return true;
		else return false;
	}
	return false;
}
int main(){
	int t,n,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&mac[i].l,&mac[i].w);
		}
		sort(mac,mac+n,cmp);
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		int cnt=0;
		node v;
		for(i=0;i<n;i++){
			if(vis[i])continue;
			cnt++;
			//printf("i=%d vis=%d\n",i,vis[i]);
			vis[i]=1;
			dp[i]=cnt;
			
			v.l=mac[i].l;
			v.w=mac[i].w;
			for(j=i+1;j<n;j++){
				if(vis[j])continue;
				if(mac[j].l>=v.l&&mac[j].w>=v.w){
					//printf("j=%d\n",j);
					vis[j]=1;
					v.l=mac[j].l;
					v.w=mac[j].w;
					dp[j]=cnt;
				}
			}
			
		}
		
		//for(i=0;i<n;i++){
		//	printf("%d%d\n",mac[i].l,mac[i].w);
		//}
		
		printf("%d\n",cnt);
	}
	return 0;
} 
