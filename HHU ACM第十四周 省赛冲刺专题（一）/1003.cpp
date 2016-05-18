#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll ans;
ll r(int m,int n){
	return ans=(ll)pow(m,n);
}
int main(){
	int t,m,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		if(ans%n!=0)
		printf("%d/%lld\n",n,r(m,n-1));
		else printf("%d/%lld\n",n,r(m,n-1));
	}
	return 0;
} 
