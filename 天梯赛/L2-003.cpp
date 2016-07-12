#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	double cnt;
	double pri;
}a[1010];

bool cmp(node x,node y){
	if((x.pri*1.0/x.cnt)>=(y.pri*1.0/y.cnt)){
		return true;
	}
	else return false;
}
int main(){
	int n,i,j;

	double b,d;
	double ans=0.0;
	scanf("%d%lf",&n,&d);
	for ( i = 0; i < n; ++i)
	{
		scanf("%lf",&b);
		a[i].cnt=b;
	}
	for ( i = 0; i < n; ++i)
	{
		scanf("%lf",&b);
		a[i].pri=b;
	}
	sort(a,a+n,cmp);
	if(d<=0){
		printf("0.00\n");
		return 0;
	}
	for ( i = 0; i < n; ++i)
	{
		//printf("%d\n",a[i].pri );
		if(d>=a[i].cnt){
			ans+=a[i].pri;
			d-=a[i].cnt;
		}
		else{
			ans+=a[i].pri*(d*1.0/a[i].cnt);
			d=0;
		}
		if(d<=0)break;
	}
	printf("%.2f\n",ans );
	return 0;
}