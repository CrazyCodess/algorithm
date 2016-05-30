#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[110][110],dp[110][110];
int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		memset(dp,0,sizeof(dp));
		for ( i = 0; i < n; ++i)
		{
			for ( j = 0; j < n; ++j)
			{
				scanf("%d",&num[i][j]);
			}
		}



	}
	return 0;
}