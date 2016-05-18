/*
¿ìËÙÃİ 
*/ 

#include<iostream>
using namespace std;
int main(){
	long long t,n,base,r;
	while(cin>>t){
		while(t--){
			r=1;
			cin>>n;
			base=n%10;
			if(base==0)r=0;
			else{	
			base=n;
			while(n!=0){
				if(n&1)
				r*=base;
				r%=10;
				base*=base;
				base%=10;
				n>>=1;
			}
			r%=10;
				}
			cout<<r<<endl;
		}
	}
	return 0;
} 
