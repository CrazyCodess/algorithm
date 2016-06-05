#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int val[555];
int aft[555];
int ans[555][2];
int n;
long long sum,cnt;
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
	memset(map,0,sizeof(map));
	scanf("%d",&n);
		for ( i = 1; i <= n; ++i)
		{
			scanf("%d",&val[i]);
			aft[i]=-1;
			//f[i]=0;
		}
		cnt=0;
		for ( i = 1; i <=n; ++i)
		{
			for ( j = i+1; j <=n; ++j)
			{
				if(gcd(val[i],val[j])==1){
					ans[cnt][0]=i;
					ans[cnt][1]=j;
					cnt++;
				}
			}
		}
		sum=0;


		for ( i = 0; i < n-1; ++i)
		{
			scanf("%d%d",&a,&b);
			//f[a]++;
			//f[b]++;
			aft[a]=b;
		}
		for ( i = 0; i <cnt; ++i)
		{
			a=ans[i][0];
			b=ans[i][1];
			
		}
		for ( i =a;i!=-1 ; i=aft[i])
		{
			sum=1;
			j=aft[i];
			while(j>0){
				map[i][j]=sum;
				map[j][i]=sum;
				sum++;
				j=aft[j];
			}
		}
/*		for ( i = 1; i <= n; ++i)
		{
			for ( j = 1; j <=n; ++j)
			{
				cout<<map[i][j]<<" ";
			}
			cout<<endl;
		}*/
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