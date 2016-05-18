#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	long long maxw,maxh,w,h,area;
	int n,i;
	while(scanf("%d",&n)!=EOF){
		if(n==0){	
			printf("1\n");
			continue;	
		}
		maxw=maxh=area=0;
		for(i=0;i<n;i++){
			scanf("%lld%lld",&h,&w);
			if(maxh<h)maxh=h;
			maxw+=w;
			area+=h*w;
		}
		printf("%lld\n",(maxh+1)*maxw-area);
	}
	return 0;
}
