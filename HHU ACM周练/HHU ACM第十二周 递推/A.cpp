#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int t,n,k;
	long long ans;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d%d",&n,&k);
			ans=(long long)pow((double)2,(double)(n-k));
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
