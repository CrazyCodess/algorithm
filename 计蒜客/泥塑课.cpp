#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
	char name[9];
	int l,w,h;
	int sum;
}stu[11];
int main(){
	int n,i,j,a,b,c,maxv,k,minv,l;

	while(scanf("%d",&n)&&n>0){
		maxv=-1;minv=555;
		for ( i = 0; i < n; ++i)
		{
			scanf("%d%d%d",&a,&b,&c);
			scanf("%s",stu[i].name);
			stu[i].l=a;
			stu[i].w=b;
			stu[i].h=c;
			stu[i].sum=a*b*c;
			if(a*b*c>maxv){
				maxv=a*b*c;
				k=i;
			}
			if(a*b*c<minv){
				minv=a*b*c;
				l=i;
			}
		}
		printf("%s took clay from %s.\n",stu[k].name,stu[l].name );

	}
	return 0;
}