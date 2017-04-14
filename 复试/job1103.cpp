#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	char s[50];
	int a,b,c;
	double det;
	int k,i,j;
	while(gets(s)!=NULL){
		//puts(s);
		k=a=b=c=0;
		while(s[k]!='='&&s[k]!='\0')k++;
		//cout<<k<<endl;
		for(i=0;i<k;i++){
			if(s[i]=='x'){
				if(s[i+1]=='^'){
					if(i-1<0||!(s[i-1]>='0'&&s[i-1]<='9')){
						a++;
					}
					else if(s[i-1]>='0'&&s[i-1]<='9'){
						a+=s[i-1]-'0';
					}
				}
				else {
					if(i-1<0||!(s[i-1]>='0'&&s[i-1]<='9')){
						b++;
					}
					else if(s[i-1]>='0'&&s[i-1]<='9'){
						b+=s[i-1]-'0';
					}					
				}
			}
			else if(s[i]>='0'&&s[i]<='9'&&s[i+1]!='x'){
				if((i-1>=0&&s[i-1]!='^')||i-1<0)c+=s[i]-'0';
			}
		}
		
		for(i=k;s[i]!='\0';i++){
			if(s[i]=='x'){
				if(s[i+1]=='^'){
					if(i-1<0||!(s[i-1]>='0'&&s[i-1]<='9')){
						a--;
					}
					else if(s[i-1]>='0'&&s[i-1]<='9'){
						a-=s[i-1]-'0';
					}
				}
				else {
					if(i-1<0||!(s[i-1]>='0'&&s[i-1]<='9')){
						b--;
					}
					else if(s[i-1]>='0'&&s[i-1]<='9'){
						b-=s[i-1]-'0';
					}					
				}
			}
			else if(s[i]>='0'&&s[i]<='9'&&s[i+1]!='x'){
				if(s[i-1]!='^')c-=s[i]-'0';
				
			}			
		}
		det=(b*b*1.0-4*a*c*1.0)*1.0;
		if(b*b*1.0-4*a*c*1.0<0){
			printf("No Solution\n");
		}	
		else{
			double ans1,ans2;
			ans1=(-b*1.0-sqrt(det*1.0))/(2*a*1.0);
			ans2=(-b*1.0+sqrt(det*1.0))/(2*a*1.0);
			printf("%.2lf %.2lf\n",ans1,ans2);
			
		}	
	}
	
	
	return 0;
}


