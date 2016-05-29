#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct point{
	int x,y,z;
}p[182];
bool cmp(const point &ele1,const point &ele2){
		if(ele1.x<ele2.x)return true;
		else if(ele1.x==ele2.x){
			if(ele1.y<ele2.y)return true;
			else if(ele1.y==ele2.y){
				if(ele1.z>ele2.z)return false;
				return true;
			}
			return false;
		}
		return false;
}
int main(){
	int n,i,j,x,y,z,cnt,cas;
	cas=1;
	while(scanf("%d",&n)!=EOF&&n){
		cnt=0;
		for ( i = 0; i < n; ++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			p[cnt].x=x;
			p[cnt].y=y;
			p[cnt].z=z;
			++cnt;
			p[cnt].x=x;
			p[cnt].y=z;
			p[cnt].z=y;
			++cnt;
			p[cnt].x=y;
			p[cnt].y=x;
			p[cnt].z=z;
			++cnt;
			p[cnt].x=y;
			p[cnt].y=z;
			p[cnt].z=x;
			++cnt;
			p[cnt].x=z;
			p[cnt].y=x;
			p[cnt].z=y;
			++cnt;
			p[cnt].x=z;
			p[cnt].y=y;
			p[cnt].z=x;
			++cnt;
		}
		//printf("%d\n", cnt);
		sort(p,p+cnt,cmp);
		for ( i = 1; i < cnt; ++i)
		{
			int temp=0;
			for ( j = 0; j < i; ++j)
			{
				if(p[j].x<p[i].x&&p[j].y<p[i].y&&p[j].z>temp)
					temp=p[j].z;
			}
			p[i].z+=temp;
		}
		int maxh=0;
		for ( i = 0; i < cnt; ++i)
		{
			if(p[i].z>maxh)maxh=p[i].z;
		}
		printf("Case %d: maximum height = %d\n", cas,maxh);
		cas++;

	}

	return 0;
}