#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string str;
char out[1001][1001];
int main(){
	int t,n,m,temp,i,j;
	
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		cin>>str;
		if(n>m){
			temp=n;
			n=m;
			m=n;
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				out[i][j]=str.at(i*m+j);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				printf("%c",out[i][j]);
			printf("\n");
		}
		
	}
	return 0;
} 
