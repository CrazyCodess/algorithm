#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
	int h,p;
}y1[110],y2[110];
int main(){
	int a,b,n,i,j,sum,cnt1=0,cnt2=0;
	scanf("%d%d%d",&a,&b,&n);
	for ( i = 0; i < n; ++i)
	{
		scanf("%d%d%d%d",&y1[i].h,&y1[i].p,&y2[i].h,&y2[i].p);
	}
	for ( i = 0; i < n; ++i)
	{
		if(a<0||b<0)break;
		sum=y1[i].h+y2[i].h;
		if(y1[i].p==sum&&y2[i].p==sum)continue;
		if(y1[i].p==sum&&y2[i].p!=sum){
			cnt1++;
			a--;
			continue;
		}
		if(y1[i].p!=sum&&y2[i].p==sum){
			cnt2++;
			b--;
			continue;
		}
	}
	if(a<0){
		printf("A\n" );
		printf("%d\n",cnt2 );
	}else if(b<0){
		printf("B\n" );
		printf("%d\n",cnt1 );		
	}


	return 0;
}