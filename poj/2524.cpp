#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int pre[50005];
int n,m,cnt;
void makeset(){
	int i;
	for(i=1;i<=n;i++)
		pre[i]=i;
	cnt=n;
}
int find(int x){
	if(x!=pre[x])
		pre[x]=find(pre[x]);
	return pre[x];
}
void uniun(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		pre[fy]=fx;
		cnt--;
	}
}
int main(){
	ll cas=0;
	int i,j,k;
	while(scanf("%d%d",&n,&m)){
		if(n==0&&m==0)break;
		makeset();
		cas++;
		for(i=0;i<m;i++){
			scanf("%d%d",&j,&k);
			uniun(j,k);
		}
		printf("Case %lld: %d\n",cas,cnt);
	}	
	return 0;
}
