#include<iostream>
#include<cstring>
using namespace std;
long int a[100000000];
int main(){
	int t,n,q,i,j,x,c;
	while(cin>>t){
		
		while(t--){
			cin>>n;
			memset(a,-1,sizeof(a));
			for(i=0;i<n;i++){
				cin>>x;
				j=1;
				while(a[j]!=-1){
					if(x<a[j])j=j*2;
					else if(x>a[j])j=j*2+1;
				}
				a[j]=x;
			}
				cin>>q;
				for(i=0;i<q;i++){
					cin>>c;
					j=1;
					if(c==a[j])cout<<endl;
					else{
						while(c!=a[j]&&a[j]!=-1){
							if(c>a[j]){
								cout<<"W";
								j=j*2+1;
							}
							else if(c<a[j]){
								cout<<"E";
								j=j*2;
							}
						}
						if(i<q-1)cout<<endl;
					}
					
				}
			}	
		}
		return 0;
	}
