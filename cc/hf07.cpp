#include<iostream>
#include<cmath>
using namespace std;
#define M  1000000007;
int b1=1,q=1,a1=0,d=0;
int  Cnm(int n,int m){
	if(n==0){
		int p=(int)pow(q*1.0,(m-1)*1.0)%M;
		int b=b1%M;
		return (b*p)%M;
	}
	if(m==0)return (int)(a1+(n-1)*d)%M;
	return (Cnm(n-1,m)+Cnm(n,m-1))%M; 
}
int main(){
	int t,i,n,m;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>b1>>q>>a1>>d>>n>>m;
		cout<<"Case #"<<i<<":"<<Cnm(n,m)<<endl;
	}
	return 0;
}
