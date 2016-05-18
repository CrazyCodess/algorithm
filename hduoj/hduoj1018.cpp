#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	int t,n;
	double l;
	int i,ans;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			l=0;
			for(i=2;i<=n;i++){
				l+=log10(i*1.0);
				
			}
			ans=int(l)+1;
			printf("%d\n",ans);
		}
	}
return 0;
}
