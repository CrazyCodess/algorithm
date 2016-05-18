#include<iostream>
using namespace std;
long int a[500005];
int main(){
	int t;
	long int n,m,z,l,i,num;
	a[0]=0;
	while(cin>>t){
		while(t--){
			cin>>n>>m>>z>>l;
			a[1]=0;
			for(i=2;i<=n;i++){
				a[i]=(a[i-1]*m+z)%l;
			}
			for(i=1;i<=n;i++)
				a[i]=a[i]+a[i];
			num=a[1];	
			for(i=2;i<=n;i++)
			num^=a[i];
			cout<<num<<endl;
		}
	}

	return 0;
}
