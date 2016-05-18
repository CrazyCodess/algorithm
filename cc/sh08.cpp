#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
long long num[100002];
int main(){
	int t,i,j,x1;
	long int q,n;
	long long m,x,y;
	scanf("%d",&t);
		for(i=1;i<=t;i++){
			memset(num,0,sizeof(num));
			scanf("%ld%lld",&q,&m);
			x=1;
			printf("Case #%d:\n",i);	
			for(j=1;j<=q;j++){
				scanf("%d",&x1);
				if(x1==1){
					scanf("%lld",&y);
					x=x*y;
					num[j]=y;
					//if(j!=q)
					printf("%I64d\n",x%m);
					//else printf("%I64d",x%m);
				}
				else if(x1==2){
					scanf("%ld",&n);
					num[j]=n;
					x=x/num[n];
					//if(j!=q)
					printf("%I64d\n",x%m);
					//else printf("%I64d",x%m);
				}
			}
		}
	
	return 0;
} 