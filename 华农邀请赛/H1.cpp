#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,k,i,ans1,ans2;
	while(scanf("%d%d",&n,&k)!=EOF){
		ans1=0;
		ans2=n;
		for(i=1;i<=100000009;i++){
			ans1=ans2;
			ans2=ans2/2+k;
			if(ans1==ans2)break;
		}
		printf("%d\n",ans1);
	}
	return 0;
} 
