#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char col1[105],col2[105];
char fl[4]={'E','N','D'};
int main(){
	int t,a,b,f;
	scanf("%d",&t);
	while(t--){
		a=0;
		b=0;
		f=0;
		memset(col2,'\0',sizeof(col2));
		while(scanf("%s",col1)){
			if(strcmp(col1,fl)==0){
				printf("%d\n",a*b);
				a=0;
				b=0;
				f=0;
				memset(col2,'\0',sizeof(col2));
				break;
			}
			if(f){//b
				if(strcmp(col1,col2)==0){
					a++;
					f=0;
				}
				else{
					b++;
					f=1;
				}
			}else{//a
				if(strcmp(col1,col2)==0){
					b++;
					f=1;
				}	
				else{
					a++;
					f=0;
				}			
			}
			strcpy(col2,col1);			
		}
			
	
		
		
	}
	return 0;
}
