#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int i,ch;
	int num[10];
	for(i=0;i<10;i++){
		ch=getchar();
		num[i]=ch-'0';
	}
	for(i=0;i<10;i++){
		printf("%d ",num[i]);
		
	}
	return 0;
}
