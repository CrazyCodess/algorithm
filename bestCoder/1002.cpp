#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool isValid(int a[],int k){
	int i,j;
	if(k<4)return false;
	for(i=0;i<k;i++)
		for(j=i+1;j<k;j++){

			if(a[i]==a[j])return false;
		}		
	for(i=0;i<k-1;i++){
		switch(a[i]){
			case 1:{
				switch((int)abs(a[i]-a[i+1])){
					case 2:return false;
					case 6:return false;
					case 8:return false;
					default:break;
				}
				break;
			}
			case 2:{
				if((int)abs(a[i]-a[i+1])==6)return false;
				break;
			}
			case 3:{
				switch((int)abs(a[i]-a[i+1])){
					case 2:return false;
					case 6:return false;
					case 4:return false;
					default:break;
				}				
				break;
			}
			case 4:{
				if((int)abs(a[i]-a[i+1])==2)return false;				
				break;
			}
			case 6:{
				if((int)abs(a[i]-a[i+1])==2)return false;
				break;
			}
			case 7:{
				switch((int)abs(a[i]-a[i+1])){
					case 2:return false;
					case 6:return false;
					case 4:return false;
					default:break;
				}
				break;
			}
			case 8:{
				if((int)abs(a[i]-a[i+1])==6)return false;
				break;
			}
			case 9:{
				switch((int)abs(a[i]-a[i+1])){
					case 2:return false;
					case 6:return false;
					case 8:return false;
					default:break;
				}
				break;
			}
			default:break;
		}
	}
	return true;
}	
int main(){
	int a[10],k,t,i;
	bool flag;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		flag=true;
		for(i=0;i<k;i++){
			scanf("%d",&a[i]);
			if(a[i]<=0||a[i]>9)flag=false;
		}
		if(!flag)printf("invalid");
		else {
			flag=isValid(a,k);
			if(flag)printf("valid");
			else printf("invalid");
		}
	}
	return 0;
}
