#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	char s[5];
	int h,m;
	int cnt=0;
	cin>>s;
	h=(s[0]-'0')*10+s[1]-'0';
	m=(s[3]-'0')*10+s[4]-'0';
	if((h>=0&&h<12)||(h==12&&m==0)){
		printf("Only %.2d:%.2d.  Too early to Dang.\n",h,m );
	}
	else {
		cnt=h-12;
		if(m>0)cnt++;
		while(cnt--){
			printf("Dang");
		}
		printf("\n");
	}
	return 0;
}