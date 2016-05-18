#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
#define N 20001
int a[N],b[N];	
int main(){
	int n,i,j;
	int sum,num;
	while(scanf("%d",&n)!=EOF){
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			
		}
		
		sort(a,a+n);
		int frontA=0,frontB=0,rearB=0;
		long long ans=0;
		num=0;
		while(++num<n)
		{
			sum=0;
			if(frontB==rearB||(frontA<n&&a[frontA]<b[frontB])){
				sum+=a[frontA];frontA++;
			}else {
				sum+=b[frontB];
				frontB++;
			}
			if(frontB==rearB||(frontA<n&&a[frontA]<b[frontB])){
				sum+=a[frontA];frontA++;
			}else {
				sum+=b[frontB];
				frontB++;
			}
			b[rearB]=sum;
			rearB++;
			ans+=sum;
		}
		printf("%lld\n",ans);
		
		
		
	}
	
	return 0;
} 
