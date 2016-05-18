#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	char c;
	int num;
	cin>>c;
	if(c>='a'&&c<='z'){
		num=c-'a'+1;
	}
	else{
		num=c-'A'+1;
	
	}
	printf("%d\n",num);
	return 0;
}
