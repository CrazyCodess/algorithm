#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long ans;
int main(){
	int n,t;
	cin>>n;
	ans=1;
	t=n;
	while(n--){
		ans*=2;
	}
	printf("2^%d = %lld\n",t,ans );
	return 0;
}