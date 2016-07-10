#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define PI acos(-1)
double area;
int main(){
	double l1,l2,a;
	scanf("%lf%lf%lf", &l1, &l2 ,&a);
/*	if(a<0){
		while(a<0){
			a+=180;
		}
	}
	else if(a>180){
		while(a>180){
			a-=180;
		}
	}*/
	double temp=sqrt((l1/2)*(l1/2)+(l2/2)*(l2/2)-l1*l2/2*cos(PI*a/180));
	//printf("%lf\n", cos(PI*a/180));
	l1=temp+l1/2+l2/2;
	area=PI*(l1/2)*(l1/2);
	printf("%.9lf\n",area );
	return 0;
}