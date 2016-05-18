#include<iostream>
#include<cstdio>
using namespace std;
int pre[100005];
int num[100005];
int n,m;
void  makeset(){
	int i;
	for(i=0;i<=n;i++){
		pre[i]=i;
		num[i]=i;
	}
		
	
}
int find(int x){
	if(x!=pre[x]){
		pre[x]=find(pre[x]);
	}
	return pre[x];
}
void uniun(int x,int y){
	if(x!=y)
	pre[y]=x;
}
int main(){
	int t,a,b;
	char c;
	//freopen("input.txt","r",stdin); 
	scanf("%d",&t);
	while(t--){
		
		scanf("%d%d",&n,&m);
		
		makeset();
		getchar();
		while(m--){
			scanf("%c%d%d%*c",&c,&a, &b);
	
			int fx=find(a);
			int fy=find(b);
			if(c=='D'){
				if(num[a]==a)num[a]=b;
				if(num[b]==b)num[b]=a;
				uniun(find(num[a]),fy);
				uniun(find(num[b]),fx);
			}
			else if(c=='A'){	
			 if(fx==fy)printf("In the same gang.\n");
				else if(find(num[a])==find(b))printf("In different gangs.\n");
				else printf("Not sure yet.\n");
			}
		}
	}
	return 0;
} 
