#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;
bool hui(char s[],int n){
	int i,j;
	
	j=0;
	//while(a[i]!='\0')i++;
	i=n-1;
	for(;j<=i;i--,j++){
		if(s[i]!=s[j])break;
	}
	if(j<=i)return false;
	return true;
}
int main(){
	char s[1001];
	int t,len;
	long int cnt;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			cnt=0;
			scanf("%s",s);
			len=strlen(s);
			do{
				if(hui(s,len)){
					cnt++;
					cnt%=1000000007; 
				}
				
			}while(next_permutation(s,s+len));
			printf("%ld\n",cnt); 
		} 
	}
	return 0;
}
