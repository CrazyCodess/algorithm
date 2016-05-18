#include<iostream>
#include<cstring>
using namespace std;
long int w[1005];
long int query(int l,int t1){
	int i;
	long int max=0;
	for(i=l;i<=t1;i++)
		if(w[i]>max)max=w[i];
		return max;
}
int main(){
	int t,n,i,q,l,t1;
	long int max;
	while(cin>>t){
		cin>>n;
		memset(w,0,sizeof(w));
		for(i=1;i<=n;i++)
			cin>>w[i];
		cin>>q;
		for(i=0;i<q;i++){
			cin>>l>>t1;
			max=query(l,t1);
			cout<<max<<endl;
		}	
	}
} 
