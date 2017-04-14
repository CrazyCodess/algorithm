#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct app{
	int num;
	int ge,gi;
	int eq;
	int pre[6];
};
struct app apps[40010];
int quo[110];
int n,m,k;
bool cmp(const app a,const app b){
	if((a.ge+a.gi)>(b.ge+b.gi)){
		return true;

	}else if((a.ge+a.gi)==(b.ge+b.gi)){
		if(a.ge>b.ge)return true;
	}
	return false;
}
struct node{
	int adnum;
	int ad[40010];
};
struct node adm[110];
//int adm[110][10010];
int main(){
	int a,b;
	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		memset(adm,0,sizeof(adm)); 
		for (int i = 0; i < m; ++i)
		{
			scanf("%d",&quo[i]);
			adm[i].adnum=0;
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d",&a,&b);
			apps[i].ge=a;
			apps[i].gi=b;
			apps[i].num=i;
			for (int j = 0; j < k; ++j)
			{
				scanf("%d",&a);
				apps[i].pre[j]=a;
			}
			apps[i].eq=0;
		}
		sort(apps,apps+20,cmp);
/*
		for (int i = 0; i < n; ++i)	
		{
			printf("%d %d %d\n", apps[i].num,apps[i].ge,apps[i].gi);
		}*/


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				if(quo[apps[i].pre[j]]>0){
					quo[apps[i].pre[j]]--;
					int c,d=i+1;//=adm[apps[i].pre[j]].
					adm[apps[i].pre[j]].ad[adm[apps[i].pre[j]].adnum++]=apps[i].num;
					if(quo[apps[i].pre[j]]==0){
						c=apps[i].ge+apps.gi;
						while((apps[d].ge+apps[d].gi)==c&&d<n){
							adm[apps[d].pre[j]].ad[adm[apps[d].pre[j]].adnum++]=apps[i].num;
							d++;
						}
					}
					break;
				}
			}
		}


		for (int i = 0; i < n; ++i)
		{
			printf("%d %d %d %d %d\n", apps[i].num,apps[i].ge+apps[i].gi,apps[i].pre[0],apps[i].pre[1],apps[i].pre[2]);
		}
	}
	return 0;
}