#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
long long value[305];
int rat[305];
long long cnt;
int main(){
	int i,j,v,k;
	while(scanf("%d",&n)!=EOF){
		cnt=0;
		v=1;
		k=-1;
		memset(rat,0,sizeof(rat));
		for(i=0;i<n;i++)
			scanf("%lld",&value[i]);
		value[i]=99999;
		for(i=0;i<n;){
			
			if(value[i]>=value[i+1]&&i!=n-1)i++;
			else if(value[i]<value[i+1]||i==n-1){
				
				if(i=k+1)
				v=rat[k]+1;
				else v=1; 
				rat[i]=v;
				printf("v=%d ",v);
				v++;
				for(j=i;j>k;j--){
					if(value[j]==value[j+1]){
						rat[j]=rat[j+1];
					}
					else if(value[j]>value[j+1]){
						rat[j]=v++;
					}
				}

				k=i;
				i++;
			}
		}
		for(i=0;i<n;i++){
			printf("%d ",rat[i]);
			cnt+=rat[i];	
		}
		//printf("\n");
		printf("%d\n",cnt);
		
	}
	return 0;
} 
