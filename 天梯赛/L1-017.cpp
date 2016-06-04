#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	char s[55];
	int cnt,num;
	cnt=0;
	num=0;
	double p;
	p=1.0;
	cin>>s;
	int len=strlen(s);
	num=len;
	if(s[0]=='-'){
		p*=1.5;
		num--;
	}
		
	if(s[len-1]%2==0)p*=2;
	for (int i = 0; i < len; ++i)
	{
		if(s[i]=='2')cnt++;
	}
	p*=(cnt*1.0/num);
	p*=100;
	printf("%.2lf%%\n", p);
	return 0;
}