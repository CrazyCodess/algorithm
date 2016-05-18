	#include<iostream>
	#include<cstdio>
	#include<cstdlib>
	#include<cstring>
	int a[102][102];
	int f[102];
	int max(int a,int b){
		return a>b?a:b;
	}
	int main(){
		int n,m,i,j,k;
		while(scanf("%d%d",&n,&m)&&n!=0&&m!=0){
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
					scanf("%d",&a[i][j]);
			memset(f,0,sizeof(f));
			for(i=1;i<=n;i++)
				for(j=m;j>=1;j--){
					for(k=1;k<=m;k++){
						if(j-k>=0)
						f[j]=max(f[j],f[j-k]+a[i][k]);//f[j]<(f[j-k]+a[i][k])?f[j-k]+a[i][k]:f[j];
					}
				}
				printf("%d\n",f[m]);
				
		}
		return 0; 
	} 
