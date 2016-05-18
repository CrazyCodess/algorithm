#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
using namespace std;
int vis[202],cnt;
char in[202],out[202];
int cmp(const void *a,const void *b)
{
  return *(char*)a-*(char*)b;  
}
void dfs(int len){
	int i;
	char c='\0';
	if(len==cnt){
		out[cnt]='\0';
		printf("%s\n",out);
	}
	for(i=0;i<cnt;i++){
		if(!vis[i]&&in[i]!=c){
			vis[i]=1;
			out[len]=in[i];
			c=in[i];
			dfs(len+1);
			vis[i]=0;
		}
	}
}
int main(){
	while(scanf("%s",in)!=EOF){
		qsort(in,strlen(in),sizeof(char),cmp);
		//printf("%s*\n",in);
		memset(vis,0,sizeof(vis));
		cnt=strlen(in);
		dfs(0);
	}
	return 0;
}
