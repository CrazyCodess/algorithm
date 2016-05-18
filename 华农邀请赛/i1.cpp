#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a[55],v[55];
int v0;
int main(){
	int n,i,fl,v1;
	double t,x;
	while(scanf("%d%d",&n,&v0)!=EOF){
		fl=1;
		x=0;
		t=0;
		v1=0;
		for(i=0;i<n;i++){
			scanf("%d%d",&a[i],&v[i]);
			if(a[i]>0&&v[i]>=v0){
				fl=0;
			}
			if(a[i]<0&&v[i]<0&&abs(v[i])>=v0){
				fl=0;
			}
		}
		if(!fl){
			printf("Bad Dog\n");
			continue;
		}
		double x1;
		for(i=0;i<n;i++){
			
			
			x1=(a[i]+v[i]*t)*1.0;
			if(x1<x){	
				if(v[i]<0&&abs(v[i])>=v0){
					fl=0;
					break;
				}
				x1=fabs(x-x1)*1.0;
				if(v[i]>=0){
					v1=v0+abs(v[i]);
				}else{
					v1=v0-abs(v[i]);
				}
				//printf("x1=%lf v1=%d",x1,v1);
				t+=x1*1.0/v1;
				x=x-v0*(x1*1.0/v1);
				//printf("x=%lf t=%lf  ",x,t);				
			}else if(x1>x){
				if(v[i]>0&&abs(v[i])>=v0){
					fl=0;
					break;
				}
				x1=a[i]+v[i]*t;
				x1=fabs(x-x1)*1.0;
				if(v[i]<=0){
					v1=v0+abs(v[i]);
				}else{
					v1=v0-v[i];
				}
				t+=x1/v1;
				//printf("x1=%lf v1=%d",x1,v1);
				x+=v0*(x1*1.0/v1);
				//printf("x=%lf t=%lf  ",x,t);				
			}

			
		}
		if(!fl)printf("Bad Dog\n");
		else
		printf("%.2lf\n",t);
			
			
		 
	}
	return 0;
}

