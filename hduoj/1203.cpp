#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double min1(double a,double b){
	return a<b?a:b;
}
int val[10010];
double dp[10010],p[10010];
int main(){
	int n,v,i,j;
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&v,&n)!=EOF&&v+n){

		for ( i = 0; i < n; ++i)
		{
			scanf("%d%lf",&val[i],&p[i]);
			p[i]=1-p[i];
			//dp[i]=1.0;
		}
		for ( i = 0; i <= v; ++i)
		{
			dp[i]=1.0;
		}
		
		for ( i = 0; i < n; ++i)
		{
			for ( j = v; j >=val[i]; j--)
			{
				dp[j]=min1(dp[j],dp[j-val[i]]*p[i]);
			}
		}
		printf("%.1f%%\n", (1-dp[v])*100);

	}



	return 0;
}