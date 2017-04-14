#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void solve(char* p,char* q){
	if(*p=='\0')return;
	char* r=p+1;
	solve(r,q);
	if(*p>='0'&&*p<='9')cout<<*p;
	if(p==q)return;
		
}
int main(){
	char  s[20];
	gets(s);
	solve(s,s);
	
	return 0;
}