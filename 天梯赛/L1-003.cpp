#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int num[11];
int main(){
	int n,i;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<10;i++){
			num[i]=0;
		}
		while(n){
			num[n%10]++;
			n/=10;
		}
		for(i=0;i<10;i++){
			if(num[i]>0)printf("%d:%d\n",i,num[i]);
		}
	}
	
	return 0;
}
