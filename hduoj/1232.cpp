#include<iostream>
#include<cstdio>
using namespace std;
int pre[1005];
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
void uniun(int a,int b){
	int fx,fy;
	fx=find(a);
	fy=find(b);
	if(fx!=fy){
		pre[fy]=fx;
		cnt--;
	}
	return;	
}
int main(){
	int i,a,b;
	while(scanf("%d%d",&n,&m)&&n){
		if(m==0){
			printf("%d\n",n-1);
			continue;
		}
		makeset();
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			uniun(a,b);
		}
		printf("%d\n",cnt-1);
	}
}
