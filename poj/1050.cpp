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
		int max=0,sum;
		for ( i = 0; i < n; ++i)
		{
			for ( j = i; j < n; ++j)
			{
				sum=0;
				for (int k = 0; k < n; ++k)
				{
					int temp=0;
					for (int m = i; m <= j; ++m)
					{
						temp+=num[k][m];	//竖着加某一列
					}
					sum+=temp;
					if(sum<0)sum=0;			//当加到小于的时候置为0，重新开始加。
					else if(sum>max)max=sum;
				}
			}
		}
		printf("%d\n", max);


	}
	return 0;
}