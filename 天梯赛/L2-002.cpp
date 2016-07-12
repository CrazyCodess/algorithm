#include <iostream>
#include <cstdio>
#include <cstring>
//#include <cmath>
#include <stdlib.h>
using namespace std;

struct List
{
	int key;
	int next;
	
}a[100010];
struct DList{
	int add;
	int key;
}b[100010];
int vis[100010]={0};
int cnt=0;
void delet(int pre,int next){
	bool flag=false;
	if(next==-1)return;
	if(vis[abs(a[next].key)]==0){//
		vis[abs(a[next].key)]=1;
	}
	else{
		flag=true;
		b[cnt].add=next;
		b[cnt].key=a[next].key;
		a[pre].next=a[next].next;
		cnt++;

	}
	if(flag){
		delet(pre,a[next].next);
	}
	else{
		delet(next,a[next].next);
	}
}
void print1(int start){
	while(start!=-1){
		if(a[start].next!=-1)
		printf("%05d %d %05d\n",  start,a[start].key,a[start].next);
		else {
			printf("%05d %d %d\n", start,a[start].key,a[start].next);
		}
		start=a[start].next;
	}
}
void print2(){
	int i;
	for (  i = 0; i < cnt-1; ++i)
	{
		
		printf("%05d %d %05d\n", b[i].add,b[i].key,b[i+1].add);
		
			
		
	}
	printf("%05d %d -1\n", b[i].add,b[i].key);
}
int main(){
	int s,i,j,n,taddre,tkey,tnext,u;
	scanf("%d%d",&s,&n);

	//printf("%05d %d\n",s,n );
	for ( i = 0; i < n; ++i)
	{
		scanf("%d%d%d",&taddre,&tkey,&tnext);
		a[taddre].key=tkey;
		a[taddre].next=tnext;
	}

	delet(-1,s);
	print1(s);
	if(cnt>1)
	print2();


	return 0;
}