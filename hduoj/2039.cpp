#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	float a[3];
	int m;
	scanf("%d",&m);
	while(m--){
		scanf("%f%f%f",&a[0],&a[1],&a[2]);
		if(a[0]<=0||a[1]<=0||a[2]<=0){
			printf("NO\n");
			continue;
		}
		sort(a,a+3);
		if(a[0]+a[1]>a[2]){
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}
