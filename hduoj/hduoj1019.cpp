#include<iostream>
#include<cstdio>
using namespace std;
long long LCM(long long n1,long long n2){
	long long a,b;
	a=n1,b=n2;
	int c;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	} 
	return (n1*n2)/a;
}
int main(){
	int t;
	long long ans,temp;
	int m,i;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			ans=1;
			scanf("%d",&m);
			for(i=0;i<m;i++){
				scanf("%lld",&temp);
				ans=LCM(ans,temp);
			}
			printf("%lld\n",ans);
		}
	
	}
	return 0;
}
