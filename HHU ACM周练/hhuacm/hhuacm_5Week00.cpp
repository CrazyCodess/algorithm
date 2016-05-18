#include<iostream>
#include<cmath>
using namespace std;
int isPrime(int n){
	int m;
	int  flag=1;
	m=sqrt(n);
	for(int i=2;i<=m;i++)
		if(n%i==0){
		flag=0;
		break;
		}
		return flag;
}
int main(){
	int n;
	 int t;
	while(cin>>t){
		while(t--){
			cin>>n;
			if(isPrime(n))cout<<n-1<<endl;
			else if(n==4)cout<<2<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}