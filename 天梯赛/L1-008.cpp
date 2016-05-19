#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int a,b,i,sum;
	while(scanf("%d%d",&a,&b)!=EOF){
		int num=0;
		sum=0;
		for(i=a;i<=b;i++){
			printf("%5d",i);
			sum+=i;
			num++;
			if(num%5==0&&i!=b)printf("\n");
		}
		printf("\nSum = %d\n",sum);
	}
	return 0;
}
