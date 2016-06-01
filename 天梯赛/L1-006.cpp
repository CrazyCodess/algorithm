#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n;
int main(){
	int i,j,k,flag,lim;
	while(scanf("%lld",&n)!=EOF){
		lim=sqrt(n);
		flag=false;
		for ( i = 12; i >=1; i--)
		{
			for ( j = 2; j <=lim ; ++j)
				{
					long long ans=1;
					for ( k = j; k <= j+i-1; ++k)
					{	
						ans*=k;

					}
					if(n%ans==0){
						flag=true;
						break;
					}
				}	
			if(flag)break;
		}
		if(flag){
			printf("%d\n",i);
			for ( k = j; k <j+i-1; ++k)
			{
				printf("%d*", k);
			}
			printf("%d\n",j+i-1 );
		}
		else{
			printf("1\n%d\n",n);
		}

	}	
	return 0;
}
