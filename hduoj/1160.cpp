#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
struct mice
{
	int w,s;
	int index;
}mou[1010];
bool cmp(const mice &ele1,const mice &ele2){
	if(ele1.w<ele2.w)return true;
	else if(ele1.w==ele2.w){
		if(ele1.s>=ele2.s)return true;
		else return false;
	}
	else return false;

}
int pre[1010];
int dp[1010];
int main(){
	int a,b,i,j,cnt,max;
	cnt=0;
	//freopen("in.txt","r",stdin);
	//memset(dp,1,sizeof(dp));
	memset(pre,-1,sizeof(pre));
	while(scanf("%d%d",&a,&b)!=EOF){
		mou[cnt].w=a;
		mou[cnt].s=b;
		mou[cnt].index=cnt+1;
		cnt++;
	}
	for ( i = 0; i < cnt; ++i)
	{
		dp[i]=1;
	}
	sort(mou,mou+cnt,cmp);
	max=0;
	for ( i = 0; i < cnt; ++i)
	{
		for ( j = 0; j < i; ++j)
		{
			if(mou[j].w<mou[i].w&&mou[j].s>mou[i].s&&dp[j]+1>dp[i]){
				dp[i]=dp[j]+1;
				pre[i]=j;
			}
		}
		if(dp[i]>max){
			max=dp[i];
			a=i;
		}
			

	}
	stack<int> s;
	s.push(a);
	while(a!=-1){
		a=pre[a];
		if(a==-1)break;
		s.push(a);
	}
	printf("%d\n", max);
	while(!s.empty()){
		cout<<mou[s.top()].index<<endl;
		s.pop();
	}
	return 0;
}