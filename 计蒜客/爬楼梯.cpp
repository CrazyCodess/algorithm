#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[51];
int plt(int n){
	if(dp[n]>0)return dp[n];
	dp[n]=plt(n-1)+plt(n-2);
	return dp[n];
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(dp,0,sizeof(dp));
		dp[1]=1;
		dp[2]=2;
		printf("%d\n",plt(n));
	}
	
	
	return 0;
} 
