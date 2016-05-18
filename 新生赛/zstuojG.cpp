#include<iostream>
#include<cstdio>
using namespace std;
int fill(int a,int b,int va,int vb,int d){
	if(va==d||vb==d)
		return 1;
		
	
	
}
int main(){
	int t,a,b,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&d);
		if(a==1||b==1){
			printf("Yes\n");
			continue; 
		}
		if(a==d||b==d){
			printf("Yes\n");
			continue; 
		}
		if(a==b&&a!=d){
			printf("No\n");
			continue;
		}
		
		
		if(fill(a,b,0,0,d))
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}
