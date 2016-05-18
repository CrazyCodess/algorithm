#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	string s;
	int i,j;
	while(cin>>s){
		if(s.size()==1){
			printf("Yes\n");
			continue;
		}
		for(i=0,j=s.size()-1;i<j;i++,j--){
			if(s.at(i)!=s.at(j))break;
		}
		if(i>=j)printf("Yes\n");
		else printf("NO\n");
	}
}
