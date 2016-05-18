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
	int n,j,e,f;
	bool flag;
	//freopen("input.txt","r",stdin); 
		while(scanf("%d",&n)!=EOF){
			flag=false;
			if(n==0)break;
			for(j=1;j<=n;j++){
				scanf("%d",&a[j]);
				if(a[j]>=0)	flag=true;
			}	
			e=1;
			ans=dp[1]=a[1];
			if(flag)
			for(j=2;j<=n;j++){
				dp[j]=max(dp[j-1]+a[j],a[j]);
				if(ans<dp[j]){
					ans=dp[j];
					e=j;	
				}
				
			}
			ans1=0;
			f=e;
			if(flag)
			for(j=e;j>0;j--){
				ans1+=a[j];
				//printf("%d ",j);
				if(ans1==ans){
					//printf("ans\n");
					f=j;
				}	
			}
			if(flag)
			printf("%d %d %d\n",ans,a[f],a[e]);
			else printf("0 %d %d\n",a[1],a[n]);
			
		}	
	return 0;
}
