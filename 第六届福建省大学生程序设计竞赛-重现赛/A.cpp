#include <iostream>
#include <map>
#include<cstdio>
#include <cmath>
using namespace std;
int main(){
	int t;
	int n,m;
	double ans;
	int i,j;
	int p[102];
	int cnt;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d%d",&n,&m);
			cnt=0;
			for(i=0;i<n;i++){
				scanf("%d",&p[i]);
				
			}
			for(i=0;i<n;i++)
				for(j=i+1;j<n;j++){
					if(p[i]<p[j]){
						int temp=p[j];
						p[j]=p[i];
						p[i]=temp;
					}
				}
				i=0;
			while(m>=0&&i<n){
				int temp=100-p[i];
				if(m>=temp){
					cnt++;
					m-=temp;
				}
				else break;
				
				
				i++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
