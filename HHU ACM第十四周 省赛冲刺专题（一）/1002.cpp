#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int t,i,j,num;
	char str[8],w;
	double p,per;
	scanf("%d",&t);
	per=1000/1024.0;
	for(i=1;i<=t;i++){
		scanf("%s",str);
		p=1.0;
		for(j=0;j<strlen(str)&&str[j]!='[';j++);
		w=str[j+1];
		switch(w){
			case 'K':{
				p=pow(per,1);
				break;
			}
			case 'M':{
				p=pow(per,2);
				break;
			}
			case 'G':{
				p=pow(per,3);
				break;
			}
			case 'T':{
				p=pow(per,4);
				break;
			}
			case 'P':{
				p=pow(per,5);
				break;
			}
			case 'E':{
				p=pow(per,6);
				break;
			}
			case 'Z':{
				p=pow(per,7);
				break;
			}
			case 'Y':{
				p=pow(per,8);
				break;
			}
			default :break;
		}
		printf("Case #%d: %.2f%%\n",i,(1-p)*100);
		
		
	}
	return 0;
}
