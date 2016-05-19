#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
//int qi(int ans){
//	int i,num;
//	for(i=1;i<=sqrt(ans);i++){
//		num=2*i*i+4*i+1;
//		if(num==ans)return i;
//		if(num>ans)return i-1;
//	}

//}
int main(){
	int n,i,j,k;
	char c;
	while((scanf("%d %c",&n,&c) != EOF) && (n <= 1000)){
		if(n<1){
			//printf("1\n");
			continue;
		}
		if(n<7){
			printf("*\n%d\n",n-1);
			continue;
		}
		k=sqrt((n+1)/2);
		 
		for(i=1;i<=k;i++){
			for(j=1;j<i;j++)
				printf(" ");
			for(j=1;j<=2*(k-i+1)-1;j++){
				printf("%c",c);
			}
			printf("\n");
		}
		
		for(i=1;i<=k-1;i++){
			for(j=1;j<=k-i-1;j++)	
				printf(" ");
			for(j=1;j<=2*i+1;j++)
				printf("%c",c);
				
			printf("\n");
				
		}
		printf("%d\n",n-2*k*k+1);
	}
	return 0;
} 
