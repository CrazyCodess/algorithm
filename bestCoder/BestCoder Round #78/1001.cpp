#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
int main(){
	int  n;
	unsigned long long a[4];
	scanf("%d",&n);
	while(n--){
		scanf("%I64u%I64u%I64u%I64u",&a[0],&a[1],&a[2],&a[3]);
		sort(a,a+4);
		if(a[0]==0){
			printf("No\n");
			continue; 
		} 
		
		
			if(a[0]+a[1]+a[2]>a[3]||a[0]>a[3]||a[0]+a[1]>a[3])printf("Yes\n");
			else printf("No\n");	
		}
	}
	return 0;
} 
