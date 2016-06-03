/*
01背包
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int val[5005];
int dp[250050];
int main(){
	int n,v,m,a,b,l,sum,i,j;
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF&&n>0){
		memset(dp,0,sizeof(dp));
		l=0;
		sum=0;
		for ( i = 0; i < n; ++i)
		{
			scanf("%d%d",&a,&b);
			while(b--){
				val[l++]=a;
				sum+=a;
			}			
		}
		for ( i = 0; i < l; ++i)
		{
			for ( j = sum/2; j >=val[i] ; j--)//01背包
			{
				dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
			}
		}
		printf("%d %d\n", sum-dp[sum/2],dp[sum/2]);


	}
	
	return 0;
}