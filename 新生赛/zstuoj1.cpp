#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int cnt=0;
	int i,j,n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int sum=m+n;
		for(i=1;i<1<<sum;i++){
			int k=2;
			int x=i;
			int c=0;
			int flag=1;
			for(j=1;j<=sum;j++)
			{
				if(x&1)
					k*=2;
				else
					k--;
				if(k==0&&x)
				{
					//flag=0;
					break;
					
				}
				c+=x&1;
				x>>1;
				
			}
			//printf("###"); 
			if(c!=n||k!=0)
				continue;
			cnt++;
			printf("###"); 
		}
		printf("%d\n",cnt);
	}
	
		return 0;
	
}
