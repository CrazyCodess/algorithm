#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int dp[102][102];
	struct node{
		int c;
		int b;
	}a[102];
int main(){
	int n,m,k,s;
	int i,j,t;
	while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
		for(i=1;i<=k;i++)
			scanf("%d%d",&a[i].c,&a[i].b);
			memset(dp,0,sizeof(dp));
		for(i=1;i<=k;++i){
			for(j=a[i].b;j<=m;++j){
				for(t=1;t<=s;++t){
					if(dp[j][t]<dp[j-a[i].b][t-1]+a[i].c){
						dp[j][t]=dp[j-a[i].b][t-1]+a[i].c;
					}
				}
			}
		}
		if(dp[m][s]>=n){
			for(i=0;i<=m;++i)
			{
				if(dp[i][s]>=n){
					printf("%d\n",m-i);
					break;
				}
			}
			
		}
		else printf("-1\n");
		
		 
	}
	
	
	return 0;
} 
