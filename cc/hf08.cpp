#include<iostream>
#include<cmath>
using namespace std;
int numFor(long long  x){
	int numCount=0;
	while(x){
		numCount++;
		x=x&(x-1);
	}
	return numCount;
}
int main(){
	int t,s1,s2,i;
	long long d;
	
	cin>>t;
	for(i=1;i<=t;i++){
		
	}
	return 0;
}