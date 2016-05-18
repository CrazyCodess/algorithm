#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int pre[30003],num[30003];
void makeset(){
	int i;
	for(i=0;i<n;i++){
		pre[i]=i;
		num[i]=1;
	}
	
	return;
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
		num[fx]+=num[fy];
	}
	return;
}
int main(){
	int i,j,k,x,y,ans;
	while(scanf("%d%d",&n,&m)){
		if(n==0&&m==0)break;
		if(m==0){
			printf("1\n");
			continue;
		}
		ans=0;
		makeset();
		for(i=0;i<m;i++){
			scanf("%d",&k);
			scanf("%d",&x);
			for(j=0;j<k-1;j++){
				scanf("%d",&y);
				uniun(x,y);
				x=y;
			}
		}
//		for(i=0;i<n;i++){
//			printf("pre=%d ",pre[i]);
//			if(pre[i]==0)ans++;
//		}
		ans=find(0);
		printf("%d\n",num[ans]);
	}
	return 0;
} 
