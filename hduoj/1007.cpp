#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct point
{
	double x,y;
}p[100002];
bool cmp1(const point a,const point b){
	if(a.x<b.x)return true;
	if(a.x>b.x)return false;
	else return a.y<b.y;
}
bool cmp2(const point a,const point b){
	if(a.y<b.y)return true;
	if(a.y>b.y)return false;
	else return a.x<b.x;	
}
double d(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	int n,i,j;
	double minr;
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(i=0;i<n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		minr=d(p[0],p[1]);
		sort(p,p+n,cmp1);
		for(i=1;i<n-1;i++){
			if(minr>d(p[i],p[i+1]))minr=d(p[i],p[i+1]);
		}
		sort(p,p+n,cmp2);
		for(i=0;i<n-1;i++){
			if(minr>d(p[i],p[i+1]))minr=d(p[i],p[i+1]);
		}
		printf("%.2lf\n",minr/2);
	}
	return 0;
} 
