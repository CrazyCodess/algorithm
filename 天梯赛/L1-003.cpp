#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num[11];
int main(){
	int i;
	string s;
	while(cin>>s){
		for(i=0;i<10;i++){
			num[i]=0;
		}
		for(i=0;i<s.length();i++){
			num[s[i]-'0']++;
		}
		for(i=0;i<10;i++){
			if(num[i]>0)printf("%d:%d\n",i,num[i]);
		}
	}
	
	return 0;
}
