#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char c[10];
	memset(c,'0',sizeof(c));
	int i;
	for(i=0;i<=5;i++)
		c[i]=getchar();
	for(i=0;i<10;i++)
	printf("%c",c[i]);
	printf("\n");
	return 0;
}