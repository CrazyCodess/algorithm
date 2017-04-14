#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
struct node{
	int n;//指数
	double a;//系数
}ans[30];
const double ex = 1e-8;  
int main(){
	int k1,k2,n;
	double a;
	node temp1[15];
	node temp2[15];
	for (int i = 0; i < 30; ++i)
	{
		ans[i].a=0.0;
	}
	scanf("%d",&k1);
	for (int j = 0; j < k1; ++j)
	{
		scanf("%d%lf",&n,&a);
		temp1[j].n=n;
		temp1[j].a=a;	
	}
	scanf("%d",&k2);
	for (int j = 0; j < k2; ++j)
	{
		scanf("%d%lf",&n,&a);
		temp2[j].n=n;
		temp2[j].a=a;	
	}
	int i=0,j=0,k=0;
	while(i<k1&&j<k2){
		if(temp1[i].n==temp2[j].n){
			ans[k].n=temp1[i].n;
			ans[k].a+=temp1[i].a+temp2[j].a;
			i++;
			j++;
			k++;				

		}
		else if(temp1[i].n<temp2[j].n){
			ans[k].n=temp2[j].n;
			ans[k].a+=temp2[j].a;
			j++;
			k++;			
			

		}
		else if(temp1[i].n>temp2[j].n){
			ans[k].n=temp1[i].n;
			ans[k].a+=temp1[i].a;
			i++;
			k++;			
						
		}
	}
	while(i<k1){
		ans[k].n=temp1[i].n;
		ans[k].a+=temp1[i].a;
		i++;
		k++;			
	

	}
	while(j<k2){
		ans[k].n=temp2[j].n;
		ans[k].a+=temp2[j].a;
		j++;
		k++;			
		

	}	

	printf("%d",k);
	for (int i = 0; i < k; ++i)
	{
		// if(!(ans[i].a>=-ex&&ans[i].a<=ex)){
		if(ans[i].a!=0){
			printf(" %d %.1lf", ans[i].n,ans[i].a);  
		}
		
	}		
	return 0;

}