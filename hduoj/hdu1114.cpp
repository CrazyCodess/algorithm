#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p[555],w[555];
int dp[1000005];
/*int minw(int a,int b){
	return a>b?b:a;
}*/
int main(){
	int t,e,f,sumw,n,i,j;
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&e,&f);
		sumw=f-e;
		scanf("%d",&n);
		for ( i = 0; i < n; ++i)
		{
			scanf("%d%d",&p[i],&w[i]);
		}
		for ( i = 0; i <= sumw; ++i)
		{
			dp[i]=9999999;
		}
		dp[0]=0;
		for ( i = 0; i < n; ++i)
		{
			for ( j = w[i]; j <= sumw; ++j)
			{
				dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
			}
		}
		if(dp[sumw]>=9999999)
			printf("This is impossible.\n" );
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[sumw]);
	}
	return 0;
}