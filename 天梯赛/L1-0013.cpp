#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long f(int n){
	long long ans=1;
	while(n){
		ans*=n;
		n--;
		if(n==0)break;
	}
	return ans;
}
long long ans;
int main(){
	int n;
	ans=0;
	cin>>n;
	while(n){
		ans+=f(n);
		n--;
		if(n==0)break;
	}	
	cout<<ans<<endl;
	return 0;
}