#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int min(int x,int y){
	return x<y?x:y;
}
int dp[5843];
int main(){
	int n,a,b,c,d;
	a=b=c=d=1;
	dp[1]=1;
	for (int i = 2; i <= 5842; ++i)
	{
		dp[i]=min(dp[a]*2,min(dp[b]*3,min(dp[c]*5,dp[d]*7)));
		if(dp[i] == dp[a]*2)++a;
		if(dp[i] == dp[b]*3)++b;
		if(dp[i] == dp[c]*5)++c;
		if(dp[i] == dp[d]*7)++d;

	}
	while(scanf("%d",&n)!=EOF&&n){//The 1000th humble number is 385875.
		printf("The %d",n);
		if(n%10==1&&n%100!=11)printf("st ");
		else if(n%10==2&&n%100!=12)printf("nd ");
		else if(n%10==3&&n%100!=13)printf("rd ");
		else printf("th ");
		printf("humble number is %d.\n", dp[n]);
	}
	return 0;
}