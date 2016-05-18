#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
ll a,b,n;
vector<ll> pme;
ll count_prime(ll x,ll n){
	pme.clear();
	ll i,j;
	for(i=2;i*i<=n;i++)
		if(n%i==0){
			pme.push_back(i);
			while(n%i==0)n/=i;
		}
	if(n>1)pme.push_back(n);
	ll sum=0,value,cnt;
	for(i=1;i<(1<<pme.size());i++){
		value=1;
		cnt=0;
		for(j=0;j<pme.size();j++){
			if(i&(1<<j)){
				value*=pme[j];
				cnt++;
			}
		}
		if(cnt&1)
			sum+=x/value;
		else sum-=x/value;
	}
	return x-sum;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&a,&b,&n);
		printf("%lld\n",count_prime(b,n)-count_prime(a-1,n));
	} 
	return 0;
} 
