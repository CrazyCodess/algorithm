#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int val[555];
long long  map[555][555];
int n;
long long sum;
void floyd(){
	int i,j,k;
	for ( k = 1; k <=n; ++k)
	{
		for ( i = 1; i <=n; ++i)
		{
			for ( j = 1; j <=n; ++j)
			{
				if(map[i][j]>map[i][k]+map[k][j])map[i][j]=map[i][k]+map[k][j];
			}
		}
	}
}
int gcd(int a,int b){
	int t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,a,b;
	//memset(map,,sizeof(map));
	scanf("%d",&n);
		for ( i = 1; i <= n; ++i)
		{
			for ( j = 1; j <=n; ++j)
			{
				map[i][j]=9999999999;
			}
			//cout<<endl;
		}	
		for ( i = 1; i <= n; ++i)
		{
			scanf("%d",&val[i]);
		}
		for ( i = 0; i < n-1; ++i)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=1;
			map[b][a]=1;
		}
		floyd();
		sum=0;
		for ( i = 1; i < n; ++i)
		{
			for ( j = i+1; j <=n; ++j)
			{
				if(gcd(val[i],val[j])==1){
					sum+=map[i][j];
				}
			}
			
		}
		printf("%lld\n",sum);
	


	return 0;
}