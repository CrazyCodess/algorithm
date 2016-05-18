#include<iostream>
using namespace std;
int main(){
	long long ans=0;
	int s,i,j,k;
	long int t[1000002],n,temp;
	long int a,b;
	while(cin>>s){
		for(i=1;i<=s;i++){
			memset(t,0,sizeof(t));
			cin>>n>>a>>b;
			for(j=0;j<n;j++)
				cin>>t[j];
			for(j=0;j<n;j++)
				for(k=j;k<n;k++){
					if(t[j]>t[k]){
						temp=t[j];
						t[j]=t[k];
						t[k]=temp;
					}
				}
			
			if(a>0){
				ans+=
				if(b==0)ans=
			}
			else if(a==0){
				
			}
			else if(a<0){
				
			}	
		}
	}
	
} 