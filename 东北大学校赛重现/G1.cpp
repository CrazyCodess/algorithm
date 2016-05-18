#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int t,i,j,n,m;
	int xu[5005][5005];
	scanf("%d",&t);
	char a[5005];
	char b[5005];
	while(t--){
		scanf("%s",a);
		scanf("%s",b);
		n=strlen(a);
		m=strlen(b);
		memset(xu,0,sizeof(xu));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				xu[i][j]=xu[i-1][j-1]+1;
				
			}
			else {
				xu[i][j]=max(xu[i][j-1],xu[i-1][j]);
			}
		}
		printf("%d\n",xu[n][m]);	
	}
	return 0;
}
