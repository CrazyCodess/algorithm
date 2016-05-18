#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
long int num[10003][2];
int pi[10003];
long int array[10003];
int comp(const void*a,const void*b)
{
return *(long int*)a-*(long int*)b;
}
#define INF 999999999
int main(){
	int t;
	int n,m;
	long int k;
	int i,j;
	scanf("%d",&t);
	int flag=1;
	int count;
	while(t--){
		//cin>>n>>m>>k;
		scanf("%d%d%d",&n,&m,&k);
		flag=1;
		count=0;
		//memset(num,0,sizeof(num));
		//	memset(pi,0,sizeof(pi));
		memset(array,INF,sizeof(array));
		for(i=1;i<=n;i++){
			scanf("%ld",&num[i][0]);
		}
		
		for(i=1;i<=m;i++){
			scanf("%d",&pi[i]);
			
		}
		for(i=1;i<=m;i++){
			if(k<0){
				flag=0;
				break;
			}
			k-=num[pi[i]][0];
			count++;
			num[pi[i]][1]=1;
		}
		
		if(flag==0||k<0){
			printf("-1\n"); 
		}else if(k>0){
			
			
			int index=0;
			for(i=1;i<=n;i++){
				if(num[i][1]==0){
					array[index]=num[i][0];
					index++;
				}
			}
			qsort(array,n,sizeof(long int),comp);
			for(i=0;i<index;i++){
				if(k<=0)break;
				if(array[i]>0){
				k-=array[i];
				count++;
				}
			
			}
			printf("%d\n",count);
		}
		else {
			printf("%d\n",count);
		}
	}
	return 0;
}
