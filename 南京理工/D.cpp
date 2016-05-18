#include<iostream>
#include<cstdio>
using namespace std;
long long ans;
long long  cmob(int n,int m){
	if(m==0||n==m)return 1;
	if(m==1||m==n-1)return n;
	int i;
	long long sum1=1,sum2=1;
	for(i=1;i<=m;i++)sum1*=i;
	for(i=n-m+1;i<=n;i++)sum2*=i;
	return sum2/sum1;
}
int main(){
	int t,n,m,temp;

	
	scanf("%d",&t);
	while(t--){
		
		scanf("%d%d",&n,&m);
		temp=n/m;
		if(temp<3){
			printf("0\n");
			continue;
		}
		ans=cmob(temp,3);
		printf("%lld\n",ans);
	}
	return 0;
}
