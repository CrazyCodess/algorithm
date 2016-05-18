#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int cmp(char a,char b){
	return a<b;
}
int main(){
	string set;
	char s[50];
	int cnt,state,i;
	while(cin>>set&&set.at(0)!='#'){
		state=1;
		cnt=set.copy(s,set.length(),0);
		for(i=0;i<cnt-1;i++)
			if(s[i]<s[i+1]){
				state=0;
				break;
			}
		if(state)printf("No Successor\n");
		else{
			while(next_permutation(s,s+cnt)){
				for(i=0;i<cnt;i++)printf("%c",s[i]);
				printf("\n");
				break;
			}
		}
		memset(s,'\0',sizeof(s));
	}
	return 0;
} 
