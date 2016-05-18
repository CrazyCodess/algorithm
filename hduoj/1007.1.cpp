#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	double r[100002][2],minr,temp;
	int n,i,j;
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(i=0;i<n;i++){
			scanf("%lf%lf",&r[i][0],&r[i][1]);
			
		}		
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(r[i][0]>r[j][0]){
					temp=r[i][0];
					r[i][0]=r[j][0];
					r[j][0]=temp;
				}
				else if(r[i][0]==r[j][0]){
					if()
				}
			}
		}
	}
}
