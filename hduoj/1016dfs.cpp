#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
//int prime[42]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1};
int vis[21],a[21],n;
bool prime(int n){
	int k,i;
	if(n<2)return false;
	for(i=2;i<=(int)sqrt(n);i++){
		if(n%i==0)return false;
	}	
	return true;
}
void dfs(int k){
	int i;
	if(k==n&&prime(a[0]+a[n-1])){
		for(i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
	}
	else{
		for(i=2;i<=n;i++){
			if(!vis[i]){
				if(prime(a[k-1]+i)){
					vis[i]=1;
					a[k++]=i;
					dfs(k);
					vis[i]=0;
					k--;
				}
			}
		}		
	}

}
int main(){
	int i;
	i=1;
	while(scanf("%d",&n)!=EOF){
		printf("Case %d:\n",i);
		memset(vis,0,sizeof(vis));
		a[0]=1;
		dfs(1);
		i++;	
		printf("\n");
	}	
	return 0;
}


