#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
#define MINUSINF 0x3f3f3f3f
int weight[550];
int value[550];
int f[10010]; 
int n,v;
int min(int a,int b){
	return a<b?a:b;
}
int CompletePack(){
	int i,j;
	f[0]=0;
	for(i=1;i<=v;i++){
		f[i]=MINUSINF;
	}
	for(i=0;i<n;i++){
		for(j=weight[i];j<=v;j++){
			if(f[j-weight[i]<MINUSINF])
			f[j]=min(f[j],f[j-weight[i]]+value[i]);
		}
	}
	if(f[v]>=MINUSINF)return -1;
	else return f[v];
}
int main(){
	int t,i;
	int empty,fill;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&empty,&fill);
		v=fill-empty;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&value[i],&weight[i]);
		}
		if(CompletePack()==-1)printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",CompletePack());
	}
	 return 0;
}

