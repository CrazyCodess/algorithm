/*Å·À­º¯Êý*/ 
#include<iostream>
#include<cmath>
using namespace std;
long int Euler(long int n){
	int i,res=n;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			n/=i;
			res=res-res/i;
			while(n%i==0)
				n/=i;
		}
		
	}
	if(n>1)res=res-res/n;
	return res;
} 
int main(){
	long int n;
	while(cin>>n&&n){
		
		cout<<Euler(n)<<endl; 
	} 
	return 0;
} 