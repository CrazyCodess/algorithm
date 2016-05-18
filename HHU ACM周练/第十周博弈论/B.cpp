#include<iostream>
#include<cstdio>
using namespace std;

#define max 4294967296
int main(){
	long long  f[48];
	int i;
	long long n;
	f[0]=f[1]=1;
	for(i=2;i<48;i++){
		f[i]=f[i-1]+f[i-2];
	}	
	int flag;
	
	//printf("%lld\n",f[47]);
	while(scanf("%lld",&n)!=EOF&&n!=0){
		flag=0;
		if(n==2)printf("Second win\n");
		else{
			for(i=2;i<48;i++){
				if(f[i]==n){
					flag=1;
					break;
				}		
			}
			if(flag)printf("Second win\n");
			else printf("First win\n");
		}
	
	}
	return 0;
} 
