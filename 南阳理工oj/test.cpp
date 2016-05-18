#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int maxk;
int att,m;
double p,ex;
void qex(){
	int len;
	if(maxk*1.0/att>(maxk/att)*1.0){
		len=maxk/att+1;
	}
	else{
		len=maxk/att;
	}
	int i;
	ex=0.0;
	printf("%.2f",p);
	for(i=1;i<=len;i++){
		if(i==len){
			ex+=pow(1-p,len-1)*i*m;
			cout<<ex<<" "<<endl;	
		}
		else{
			ex+=p*pow(1-p,i-1)*i*m;
			cout<<ex<<" ";
		}
	}
}

int main(){
	int temp,t,i,d;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d%d%d",&att,&m,&temp,&d);
		p=temp*1.0/100; 
		scanf("%d",&maxk);
		printf("$");
		qex();
		//for(j=1;j<=n;j++){
		//	scanf("%d%d%d",&dot[j].x,&dot[j].y,&dot[j].k)
		//}
		
		
		
		
		printf("Case #%d: %.2f\n",i,ex);
	}

	return 0;
	
}
