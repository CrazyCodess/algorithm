#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1000000];
int main(){
	long long n;
	int t,maxt,i,mint;
	while(scanf("%lld",&n)!=EOF){
		maxt=0;
		mint=999999;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++){
			scanf("%d",&t);
			if(t>maxt)maxt=t;
			if(t<mint)mint=t;
			dp[t]++;
		}
		int ans=(n+1)/2;
		for(i=mint;i<=maxt;i++){
			if(dp[i]>=ans){
				ans=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
