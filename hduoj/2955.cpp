#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double dp[10010],val[110];
int cost[110];
int main(){
	int n,t,i,j,sum;
	double bel;
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%lf%d",&bel,&n);
		bel=1-bel;
		sum=0;
		for ( i = 0; i < n; ++i)
		{
			scanf("%d%lf",&cost[i],&val[i]);
			val[i]=1-val[i];
			sum+=cost[i];

		}
		for ( i = 1; i <= sum; ++i)
		{
			dp[i]=0;
		}
		dp[0]=1;
		for ( i = 0; i < n; ++i)
		{
			for ( j = sum; j >= cost[i]; j--)
			{
				dp[j]=max(dp[j],dp[j-cost[i]]*val[i]);
			}
		}
		for ( i = sum; i >= 0; i--)
		{

			if(dp[i]>=bel){
				printf("%d\n", i);
				break;
			}    
		}

	}
	return 0;
}