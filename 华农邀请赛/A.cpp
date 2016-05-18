#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		printf("%.2f\n",b*1.0/a);
	}
	return 0;
}
