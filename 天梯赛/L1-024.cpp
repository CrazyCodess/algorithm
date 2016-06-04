#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int d;
	scanf("%d",&d);
	if(d==5)printf("7\n");
	else printf("%d\n",(d+2)%7 );
	return 0;
}