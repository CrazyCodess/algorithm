#include<iostream>
#include<cstdio>
using namespace std;
int  cut_cake(int a,int b){
	if(a==b)return 1;
	if(a>b){
		return cut_cake(a-b,b)+1;
		
	}
	else if(b>a){
		return cut_cake(a,b-a)+1;
		
	}
	
}
int main(){
	int t,cnt,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		cnt=0;
		cnt+=cut_cake(n,m);
		printf("%d\n",cnt);
	}
	return 0;
} 
