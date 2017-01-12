	#include <iostream>
	#include <cstdio>
	#include <cstring>
	using namespace std;
	char cha[20],chb[20]; 
	int main(){
		bool isApos,isBpos;			
		int lenA,lenB,i;
		long long num1,num2;
		//freopen("in.txt","r",stdin);
		while(scanf("%s %s",cha,chb)!=EOF){
			num1=num2=0;
			isApos=true;	
			isBpos=true;
			lenA=strlen(cha);
			lenB=strlen(chb);
			if(cha[0]=='-')isApos=false;
			if(chb[0]=='-')isBpos=false;
			i=0;
			while(i<lenA){
				if(cha[i]>='0'&&cha[i]<='9')
				num1=num1*10+cha[i]-'0';
				i++;
			}	
			i=0;			
			while(i<lenB){
				if(chb[i]>='0'&&chb[i]<='9')
				num2=num2*10+chb[i]-'0';
				i++;
			}	
			if(!isApos)num1=-num1;
			if(!isBpos)num2=-num2;
			printf("%lld\n",num1+num2 );
			memset(cha,0,sizeof(cha));  
			memset(chb,0,sizeof(chb)); 
		}

		return 0;
	}