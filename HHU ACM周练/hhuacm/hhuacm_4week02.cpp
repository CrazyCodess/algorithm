#include<iostream>
using namespace std;
#define INF 30005;
int dp[1000]; 
int main(){
	int n,x,minh,flag,res,tempi,i;
	while(cin>>n&&n){
		res=0;
		while(n--){
			cin>>x;
			minh=INF;
			flag=0;
			for(i=0;i<res;i++){
				if(dp[i]>=x&&minh>dp[i]-x){
					flag=1;
					minh=dp[i]-x;
					tempi=i;
				}
			}
			if(flag==0){
				dp[res]=x;
				res++;
			}	
			else
				dp[tempi]=x;
				
		}
		cout<<res<<endl;
	}
	return 0;
} 
