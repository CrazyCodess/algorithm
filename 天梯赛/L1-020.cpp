#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int per[100010];
int main(){
	
	int n,k,m,i,j;
	memset(per,0,sizeof(per));
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&k);
		for ( j = 0; j < k; ++j)
		{
			scanf("%d",&m);
			per[m]+=k;

		}
		
	}
	int sum=0;
	scanf("%d",&m);
	for ( i = 0; i < m; ++i)
	{
		scanf("%d",&k);
		if(per[k]==0||per[k]==1){
			if(sum>0)printf(" ");
			printf("%.5d", k);
			per[k]=-1;
			sum++;
		}
	}
	if(sum<=0){
		printf("No one is handsome");
	}
	printf("\n");
	return 0;
}