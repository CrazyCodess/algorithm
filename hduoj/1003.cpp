#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef int  ll;
#define MIN -9999
ll max(ll a,int b){
	return a>b?a:b;
}
ll dp[100005];
ll ans,ans1;
int a[100005];
int main(){
	int t,n,i,j,e,f;
	//freopen("input.txt","r",stdin); 
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		//ans=MIN;
		//memset(dp,MIN,sizeof(dp));
		scanf("%d",&n);
		for(j=1;j<=n;j++)
			scanf("%d",&a[j]);
		e=1;
		ans=dp[1]=a[1];
		for(j=2;j<=n;j++){
			dp[j]=max(dp[j-1]+a[j],a[j]);
			if(ans<dp[j]){
				ans=dp[j];
				e=j;	
			}
		}
		ans1=0;
		f=e;
		for(j=e;j>0;j--){
			ans1+=a[j];
			//printf("%d ",j);
			if(ans1==ans){
				//printf("ans\n");
				f=j;
			}	
		}
		
		printf("Case %d:\n%d %d %d\n",i,ans,f,e);
		if(i!=t)printf("\n");
			
	}
	return 0;
}
