#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1005],num[1005];
int main(){
	int n,i,j,max;
	while(scanf("%d",&n)!=EOF&&n){
		memset(dp,0,sizeof(dp));
		
		for ( i = 0; i < n; ++i)
		{
			scanf("%d",&num[i]);
		}
		max=dp[0]=num[0];
		for ( i = 1; i < n; ++i)
		{
			dp[i]=num[i];
			for ( j = 0; j < i; ++j)
			{
				if(num[j]<num[i]){
					if(dp[i]<dp[j]+num[i])
					dp[i]=dp[j]+num[i];
				}
					
			}
			if(max<dp[i])max=dp[i];
		}

		printf("%d\n",max );
	}
	return 0;
}