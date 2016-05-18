#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str1[2105],str2[2105];
bool dp[2105][2105];
int main(){
	int n,m,k,i,j;
	while(scanf("%s",str1)!=EOF){
		 memset(dp,0,sizeof(dp)); 
		scanf("%s",str2);
		scanf("%d",&k);
		n=strlen(str1);
		m=strlen(str2);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(str1[i-1]==str2[j-1])
				 	dp[i][j]=dp[i-1][j-1]+1;
				
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		
		
		
		
		cout<<str1<<"*"<<str2<<endl;
	}
	return 0;
} 
