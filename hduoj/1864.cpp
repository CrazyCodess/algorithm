#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[32];
int dp[3000050];
int main(){
	double q,price;
	int sum,sum1;
	int n,i,j,m,flag,cnt,p,b,c,v;
	char tp;
	//freopen("in.txt","r",stdin);
	while(scanf("%lf%d",&q,&n)!=EOF&&n){
		memset(dp,0,sizeof(dp));
		sum=(int)(q*100);
		cnt=0;
		for ( i = 0; i < n; ++i)
		{	
			a[i]=0;
			scanf("%d",&m);
			flag=1;
			sum1=0;
			p=b=c=0;
			while(m--){
				scanf(" %c:%lf",&tp,&price);
				v=(int)(price*100);
				if(tp=='A'&&p+v<=60000)
					p+=v;
				else if(tp=='B'&&b+v<=60000)
					b+=v;
				else if(tp=='C'&&c+v<=60000)
					c+=v;
				else flag=0;
			}
			if(flag&&p<=60000&&b<=60000&&c<=60000&&p+b+c<=100000){
				a[i]=p+b+c;
				cnt++;
			}
			
		}
		for ( i = 0; i < cnt; ++i)
		{
			for ( j = sum; j >=a[i]; j--)
			{
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
			}
		}

		printf("%.2lf\n", dp[sum]/100.0);

	}
	return 0;
}