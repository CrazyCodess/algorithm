#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[50005];
long long num[50005];
int s[50005];
int main(){
	int n,i,j,maxlen;
	while(scanf("%d",&n)!=EOF){
		//memset(dp,1,sizeof(dp));
		//memset(s,0,sizeof(s));
		for ( i = 0; i < n; ++i)
		{
			scanf("%lld",&num[i]);
			dp[i]=1;
			s[i]=1;
		}
		maxlen=0;
		for ( i = 1; i < n; ++i)
		{
			for ( j = 0; j < i; ++j)
			{
				if (num[j]>num[i]&&dp[j]+1>dp[i])
				{
					dp[i]=dp[j]+1;
					s[i]=s[j];
				}
				else if (num[j]>num[i]&&dp[j]+1==dp[i])
				{
					s[i]=s[i]+s[j];
				}
				else if(num[j]==num[i]&&dp[i]==dp[j]){
					s[i]=0;
					//dp[i]=0;
				}
			}

/*			for ( j = 0; j < i; ++j)
			{
				
			}*/
			if(maxlen<dp[i])maxlen=dp[i];

		}
		
		int cnt=0;
		for ( i = 0; i < n; ++i)
		{

			if (dp[i]==maxlen)
			{
/*				int f=1;
				for ( j = i-1; j >= 0; j--)
				{
					if(num[i]==num[j]){
						f=0;
						break;
					}
				}	
				if(f)*/			
				cnt+=s[i];
			}
		}
		printf("%d %d\n",maxlen,cnt );


	}

	return 0;
}
