#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int seq[2009];
int dp[2005][2005]; 
int main(){
	int n,i,j,k,l;
	while(scanf("%d",&n)!=EOF){
		
		for(i=0;i<n;i++){
			scanf("%d",&seq[i]);
		}
		if(n<=2){
			printf("%d\n",n);
			continue;
		}
		sort(seq,seq+n);
		memset(dp,0,sizeof(dp));
		for(i)
		//d=seq[1]-seq[0];
		//for(i=0;i<n;i++)printf("%d ",seq[i]);
		//printf("\n");
		sort(dp,dp+n);
		printf("%d\n",dp[n-1]);
	}
	return 0;
	
}
