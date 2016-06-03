#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1010];
int val[1010];
int main(){
	int n,i,j,m,maxv;
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF&&n){
		memset(dp,0,sizeof(dp));
		maxv=0;
		for ( i = 0; i < n; ++i)
		{
			scanf("%d",&val[i]);
		}
		sort(val,val+n);
		maxv=val[n-1];
		scanf("%d",&m);
		if(m<5){
			printf("%d\n", m);
			continue;
		}
		m=m-5;
		for ( i = 0; i < n-1; ++i)
		{
			for ( j = m; j >= val[i]; j--)
			{
				dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
			}
		}
		printf("%d\n", m-dp[m]+5-maxv);

	}


}