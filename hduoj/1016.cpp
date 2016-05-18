#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool prime(int n){
	int k,i;
	if(n<2)return false;
	for(i=2;i<=(int)sqrt(n);i++){
		if(n%i==0)return false;
	}	
	return true;
}
int main(){
	int c[20],i,n;
	int k;
	for(i=0;i<20;i++)c[i]=i+2;
	int flag=1; 
	while(scanf("%d",&n)!=EOF){
		k=1;
		printf("Case %d:\n",k);
		while(next_permutation(c,c+n-1)){
			flag=1;
			if(!prime(1+c[0])||!prime(1+c[n-2]))continue;
			for(i=0;i<n-2;i++){
				if(!prime(c[i]+c[i+1])){
					flag=0;
					break;
				}
			}
			if(!flag)continue;
			
			printf("1");
			for(i=0;i<n-1;i++)
				printf("%d",c[i]);
			printf("\n");
		}
		printf("\n");
		k++;
	}
	return 0;
	
}
