#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
	int t,n,a[1001];
	int f;
	int i;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			f=0;
			scanf("%d",&n);

			for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			if(n==1){
				printf("%d\n",a[0]);
				continue;
			}			
			
			
			printf("%d\n",f);
		}
	}
	
	return 0;
}
