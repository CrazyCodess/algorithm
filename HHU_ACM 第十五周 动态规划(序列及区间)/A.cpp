#include<iostream>
#include<cstdio>
using namespace std;
#define MIN -99999 
int dp[1000005][1000005];
int s[1000005];
int m,n;
int main(){
	int i,j,k;
	while(scanf("%d%d",&m,&n)!=EOF){
		memset(dp,MIN,sizeof(dp));
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		
	}
	return 0;
} 
