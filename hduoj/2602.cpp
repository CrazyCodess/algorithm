#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 int vol[1010],val[1010],dp[1010];
int main(){
	int t,n,v,i,j;
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&t)!=EOF){
		while(t--){
			memset(dp,0,sizeof(dp));
			scanf("%d%d",&n,&v);
			for ( i = 0; i < n; ++i)
			{
				scanf("%d",&val[i]);
			}
			for ( i = 0; i < n; ++i)
			{
				scanf("%d",&vol[i]);
			}	

			for ( i = 0; i < n; ++i)
					{
						for ( j = v; j >=vol[i]; j--)
						{
							dp[j]=max(dp[j],dp[j-vol[i]]+val[i]);
						}
					}	
			printf("%d\n", dp[v]);	
		}
	}

	return 0;
}