#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int pre[1005];
int cnt;
void init(){
	int i;
	for(i=1;i<=m;i++){
		pre[i]=i;
		cnt=0;
	}
	
} 
int find(int x){
	if(x!=pre[x])
		pre[x]=find(pre[x]);
	return pre[x];
}
void uniun(int fx,int fy){
	pre[fy]=fx;
}
int main(){
	int i,a,b;
	scanf("%d%d",&n,&m);
		init();
		for(i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			int fx=find(a);
			int fy=find(b);
			if(fx==fy)cnt++;
			else
			uniun(fx,fy);
		}
		printf("%d\n",cnt);
	
	return 0;
} 
