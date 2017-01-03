#include <iostream>
#include <cstdio>
using namespace std;
int d[10010];
void swap(int *a,int *b){
	if(*a!=*b){
		int temp=*a;
		*a=*b;
		*b=temp;
	}
}
int partition(int a[],int p,int r){
	int i=p;
	int x=a[p];
	for(int j=i+1;j<=r;j++){
		if(a[j]<x)
		swap(&a[++i],&a[j]);

	}
	swap(&a[i],&a[p]);
	return i;
}
void qsort(int a[],int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		qsort(a,p,q-1);
		qsort(a,q+1,r);
	}
}
int main(){
	int n,cow;
	while(scanf("%d",&n)!=EOF){
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&d[i]);
		}
		qsort(d,0,n-1);
		printf("%d\n", d[n/2]);
	}
	return 0;
}