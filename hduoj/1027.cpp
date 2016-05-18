#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int ans[1002],i;

	int n,m,k;
	
	while(scanf("%d%d",&n,&m)!=EOF){
	for(i=0;i<1002;i++){
		ans[i]=i+1;
	}		
		k=2;
		if(m==1){
				for(i=0;i<n-1;i++)printf("%d ",ans[i]);
				printf("%d\n",ans[n-1]); 
							
		}else
		while(next_permutation(ans,ans+n)){
			if(k==m){
				for(i=0;i<n-1;i++)printf("%d ",ans[i]);
				printf("%d\n",ans[n-1]); 
				break;
			}
			k++;
		}
	}
	return 0;
}
