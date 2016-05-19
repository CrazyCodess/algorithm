#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char pin[12][6]={{'l','i','n','g'},{'y','i'},{'e','r'},{'s','a','n'},{'s','i'},{'w','u'},{'l','i','u'},
				{'q','i'},{'b','a'},{'j','i','u'}};
char num[105];
int main(){
	int i,len;
	while(cin>>num){
		len=strlen(num);
		for(i=0;i<len;i++){
			if(i==0&&num[i]=='-'){
				printf("fu ");
				
			}
			else{
				printf("%s",pin[num[i]-'0']);
				if(i<len-1)printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
} 
