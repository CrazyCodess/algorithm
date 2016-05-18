#include<iostream>
#include<cstdio>
using namespace std;
int pre[50005];
int rel[50005];
int n;
long long k,cnt;
void init(){
	int i;
	for(i=1;i<=n;i++){
		pre[i]=i;
		rel[i]=0;
		cnt=0;
	}
}
int find(int x){
	if(x!=pre[x]){
		int temp=pre[x];
		pre[x]=find(pre[x]);
		rel[x]=(rel[x]+rel[temp])%3;
		
	}
	return pre[x];
}
void merge(int a,int b,int p,int q,int d){
	pre[p]=q;
	rel[p]=(rel[b]-rel[a]+2+d)%3;
}
int main(){
	int d,x,y,i;
//freopen("test.txt","r",stdin);   
scanf("%d%lld",&n,&k);
	//while(scanf("%d%lld",&n,&k)!=EOF){
		//printf("$\n");
		init();
		for(i=0;i<k;i++){
			scanf("%d%d%d",&d,&x,&y);
			if((d==2&&x==y)||x>n||y>n){
				cnt++;
				continue;
			}
			int p=find(x);
			int q=find(y);
			if(p==q&&(rel[y]+d+2)%3!=rel[x]){
				cnt++;
				continue;
				
			//	if(d==1){
			//		if(rel[x]!=rel[y])cnt++;
			//		break;
			//	}
			//	else if(d==2){
			//		if((rel[y]-rel[x]+3)%3!=1)cnt++;
			//		break;
			//	}
			}
			else{
				merge(x,y,p,q,d);
			}
		}
		printf("%lld\n",cnt);
	//}
	return 0;
} 
