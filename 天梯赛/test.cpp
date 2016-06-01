#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long int gcd(long int a,long int b){
	long int t;
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	
	while(b){
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int main(){
	long int a,b;
	while(cin>>a>>b){
		cout<<gcd(a,b)<<endl;
	}
	return 0;
}