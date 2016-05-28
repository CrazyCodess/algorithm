#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[251][251];
char s[251][251];
int num[251];
int min(int a,int b,int c){
	if(a>b)a=b;
	if(a>c)a=c;
	return a;
}
int main(){
	int n,i,j;
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		for ( i = 0; i < n; ++i)
			for ( j = 0; j < n; ++j)
				cin>>s[i][j];
		
		for ( i = n-1; i>=0; i--)
			{
				for ( j = n-1; j >=0; j--)
				{
					if (s[i][j]-'0')
					{
						dp[i][j]=min(dp[i+1][j],dp[i][j+1],dp[i+1][j+1])+1;
					}
					for (int k = 2; k <=dp[i][j]; ++k)
					{
						num[k]++;
					}

				}

				
			}	

			for ( i = 2; i <= n; ++i)
			{
				if (num[i])
				{
					printf("%d %d\n", i , num[i] );
				}
			}
		

	


	return 0;
}