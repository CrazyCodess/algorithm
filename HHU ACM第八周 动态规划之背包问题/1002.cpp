	#include<iostream>
	#include<cstdio>
	#include<cstdlib>
	#include<cstring>
	using namespace std;
	int dp[102];
	struct node{
		int price;
		int weight;
		int count;
	}mi[102];
	int main(){
		int c;
		int i,j,k;
		int n,m,mcount;
		scanf("%d",&c);
		mi[0]={0,0,0};
		while(c--){
			scanf("%d%d",&n,&m);
			//mcount=-1;
			for(i=0;i<m;i++){
				scanf("%d%d%d",&mi[i].price,&mi[i].weight,&mi[i].count);
				//if(mi[i].count>mcount)mcount=mi[i].count;
			}
			memset(dp,0,sizeof(dp));	
			for(i=0;i<m;i++){
				for(j=1;j<=mi[i].count;j++){
					for(k=n;k>=mi[i].price;k--)
					if(dp[k]<dp[k-mi[i].price]+mi[i].weight){
						dp[k]=dp[k-mi[i].price]+mi[i].weight;					
					}
				}
			}
				
			printf("%d\n",dp[n]);
		}
		return 0;
	}
