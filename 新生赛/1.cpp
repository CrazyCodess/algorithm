#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int countz(int a){
	if(a==1)return 0;
	return abs(a/2-(a-a/2))+countz(a/2)+countz(a-a/2);
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",countz(n));
	}
	return 0;
} 
