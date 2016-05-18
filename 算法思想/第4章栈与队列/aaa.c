#include<stdio.h>
int kk(int m,int n)
{
	if(m==0)
	return n+1;
	if(n==0)
	return kk(m-1,1);
	else
	return kk(m-1,kk(m,n-1));
}
int main(){
	
	int a;
	a=kk(2,1);
	printf("a=%d",a);
	return 0;
	
}