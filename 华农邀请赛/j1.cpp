#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int seq[2009];
int dp[2009],d,dp1[2009];
int main(){
	int n,i,j,k,l;
	while(scanf("%d",&n)!=EOF){
		
		for(i=0;i<n;i++){
			scanf("%d",&seq[i]);
			dp[i]=1;
			dp1[i]=1;
		}
		if(n<=2){
			printf("%d\n",n);
			continue;
		}
		sort(seq,seq+n);
		//d=seq[1]-seq[0];
		for(i=0;i<n;i++){
			dp1[i]=1;
			for(j=i+1;j<n;j++){
				dp1[j]=2;
				d=seq[j]-seq[i];
				if(dp1[j]>dp[j])dp[j]=dp1[j];
				l=j;
				for(k=j+1;k<n;k++){
					dp1[k]=1;
					
					if(seq[k]-seq[l]==d){
							dp1[k]=dp1[l]+1;
							if(dp1[k]>dp[k])dp[k]=dp1[k];
							l=k;
					}
					
				}	
			}	
		}
		//for(i=0;i<n;i++)printf("%d ",seq[i]);
		//printf("\n");
		sort(dp,dp+n);
		printf("%d\n",dp[n-1]);
	}
	return 0;
	
}
