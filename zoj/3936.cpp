#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int t;
	int a,b,c,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d %d\n%d %d\n",c,b+d,a,b+d);
	}
	return 0;
}
