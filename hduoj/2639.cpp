#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 int vol[1010],val[1010],dp[1010][31],a[31],b[31];
int main(){
	int t,n,v,i,j,k;
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&t)!=EOF){
		while(t--){
			memset(dp,0,sizeof(dp));
			scanf("%d%d%d",&n,&v,&k);
			for ( i = 0; i < n; ++i)
			{
				scanf("%d",&val[i]);
			}
			for ( i = 0; i < n; ++i)
			{
				scanf("%d",&vol[i]);
			}	

			for ( i = 0; i < n; ++i)
					{
						for ( j = v; j >=vol[i]; j--)
						{	
							int d;
							for ( d = 1; d <= k; ++d)
							{
								a[d]=dp[j-vol[i]][d]+val[i];
								b[d]=dp[j][d];
							}
							int x=1,y=1,z=1;
							a[d]=b[d]=-1;
							while(z<=k&&(x<=k||y<=k)){
								if(a[x]>b[y]){
									dp[j][z]=a[x];
									x++;
								}else{
									dp[j][z]=b[y];
									y++;
								}
								if(dp[j][z]!=dp[j][z-1])
									z++;
							}


							//dp[j]=max(dp[j],dp[j-vol[i]]+val[i]);
						}
					}	
					printf("%d\n",dp[v][k]);
/*			if(k!=1)printf("0\n");	
			else		
			printf("%d\n", dp[i]);	*/
		}
	}

	return 0;
}