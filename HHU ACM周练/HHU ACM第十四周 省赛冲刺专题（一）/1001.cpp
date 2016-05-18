#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[5005];
bool dp[5005][5005];
int main(){
	int len,i,j,cnt,l,r;
	while(scanf("%s",str)!=EOF){
	
		len=strlen(str);
			cnt=len;
		for(i = 0 ; i < len ; i++){
			l=i-1;
			r=i+1;
			while(l>=0&&r<len&&str[l]==str[r]){
				l--;r++;
				cnt++;
			}
			l=i;r=i+1;
			while(l>=0&&r<len&&str[l]==str[r]){
				l--;r++;
				cnt++;
			}			
		}
		printf("%d\n",cnt);
		//cout<<cnt<<endl;
	}
	return 0;
} 
