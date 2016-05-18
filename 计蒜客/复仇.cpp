#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Dota{
	int x,y,k;
};
Dota dot[1005];
int maxk;
int att,m,n;
double p,ex;
int pre[1005],num[1005];
bool cmp(const Dota &dot1,const Dota &dot2){
	if(dot1.x>dot2.x)return false;
	else if(dot1.x==dot2.x){
		if(dot1.y>dot2.y)return false;
	} 
	return true;
}
double qdis(int i,int j){
	double d=(dot[i].x-dot[j].x)*(dot[i].x-dot[j].x)+(dot[i].y-dot[j].y)*(dot[i].y-dot[j].y);
	return sqrt(d);
}
void qex(int mak){
	int len;
	if(mak*1.0/att>(mak/att)*1.0){
		len=mak/att+1;
	}
	else{
		len=mak/att;
	}
	//printf("len=%d\n",len); 
	int i;
	for(i=1;i<=len;i++){
		if(i==len){
			ex+=pow(1-p,len-1)*i*m;	
		}
		else{
			ex+=p*pow(1-p,i-1)*i*m;
			
		}
	}
}
void init(){
	int i;
	for(i=1;i<=n;i++){
		pre[i]=i;
		num[i]=dot[i].k;
	}
	ex=0.0;	
}
int find(int x){
	if(x!=pre[x])
		pre[x]=find(pre[x]);
	return pre[x];
}
void uniun(int x,int y,int k){
	if(x!=y){
		pre[y]=x;
		if(num[x]<k)num[x]=k;
	} 
}
int main(){
	int temp,t,i,d,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d%d%d%d",&n,&att,&m,&temp,&d);
		p=temp*1.0/100; 
		for(j=1;j<=n;j++){
			scanf("%d%d%d",&dot[j].x,&dot[j].y,&dot[j].k);
		}
		sort(dot+1,dot+n+1,cmp);
		init();
		for(j=1;j<n;j++){
			if(qdis(j,j+1)<d*1.0){
				int fx=find(j);
				int fy=find(j+1);
				uniun(fx,fy,dot[j+1].k);
			}
		}
		for(j=1;j<=n;j++){
			if(pre[j]==j){
				qex(num[j]);
			}
		}
		printf("Case #%d: %.2f\n",i,ex);
	}

	return 0;
	
}
