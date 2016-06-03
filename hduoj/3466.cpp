#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	int p,q,v;
}a[555];
int dp[5555];
bool cmp( node x, node y){
	return x.q-x.p<y.q-y.p;
}
int main(){
	int n,m,i,j;
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(dp,0,sizeof(dp));
		for ( i = 0; i < n; ++i)
		{
			scanf("%d%d%d",&a[i].p,&a[i].q,&a[i].v);
		}
		sort(a,a+n,cmp);
		for ( i = 0; i < n; ++i)
		{
			for ( j = m; j >= a[i].q; j--)
			{
				dp[j]=max(dp[j],dp[j-a[i].p]+a[i].v);
			}
		}
		printf("%d\n",dp[m] );

	}

	return 0;
}