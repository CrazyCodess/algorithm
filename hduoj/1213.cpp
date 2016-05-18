#include<iostream>
#include<cstdio>
using namespace std;
int pre[1005];
int cnt;
int n,m;
void makeset(){
	int i;
	for(i=1;i<=n;i++)
		pre[i]=i;
	cnt=n;
}
int find(int x){
	if(x!=pre[x])
		x=find(pre[x]);
	return pre[x];
}
void uniun(int a,int b){
	int fx=find(a);
	int fy=find(b);
	if(fx!=fy){
		pre[fx]=fy;
		cnt--;
	}
	return;
}
int main(){
	int t,i;
	scanf("%d",&t);
	int a,b;
	while(t--){
		scanf("%d%d",&n,&m);
		makeset();
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			uniun(a,b);
		}
		printf("%d\n",cnt);
	}
	return 0;
}
