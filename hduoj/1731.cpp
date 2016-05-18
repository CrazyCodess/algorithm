#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
using namespace std;
int cmp(char a,char b){
	return a<b;
}
int main(){
	char s[50];
	int cnt,i;
	while(scanf("%s",s)!=EOF){
		i=0;
		cnt=strlen(s);
		sort(s,s+cnt,cmp);
			do{
				i++;
				printf("%s\n",s);
			}while(next_permutation(s,s+cnt));
	}
	return 0;
} 
