/*01±³°ü*/
#include<iostream>
#include<cstring>
using namespace std;
int dp[1001][1001];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int t,n,v,vol[1001],val[1001],i,j;
	while(cin>>t){

		while(t--){
			cin>>n>>v;
			for(i=1;i<=n;i++)
				cin>>val[i];
			for(i=1;i<=n;i++)
				cin>>vol[i];
		 	memset(dp,0,sizeof(dp));
		 	for(i=1;i<=n;i++){
	 			for(j=0;j<=v;j++){
			 		if(vol[i]<=j)
			 			dp[i][j]=max(dp[i-1][j],dp[i-1][j-vol[i]]+val[i]);
		 			else dp[i][j]=dp[i-1][j];
			 	}
			 	
	 		}
	 		cout<<dp[n][v]<<endl;
		}
			
	}
	return 0;
} 

 