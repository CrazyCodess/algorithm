#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
int num[1005];
int dp[1005];
int pre[1005];
int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		memset(dp,1,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		for ( i = 0; i < n; ++i)
		{
			scanf("%d",&num[i]);
		}
		for ( i = 1; i < n; ++i)
		{
			for ( j = 0; j < i; ++j)
			{
				if(num[i]<num[j]&&dp[j]+1>dp[i]){
					dp[i]=dp[j]+1;
					pre[i]=j;
				}
			}
		}
		int maxlen=0;
		for ( i = 0; i < n; ++i)
		{
			if (maxlen<dp[i])
			{
				maxlen=dp[i];
				j=i;
			}
		}
		stack<int> v;
		while(j!=-1){
			v.push(num[j]);
			j=pre[j];
		}
		printf("%d", v.top());
		v.pop();
		while(!v.empty()){
			printf(" %d", v.top());
			v.pop();
		}
		printf("\n");

	}
	return 0;
}