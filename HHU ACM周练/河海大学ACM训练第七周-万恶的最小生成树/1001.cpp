/*
poj1789Truck History 
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 999999999; 
int map[2002][2002];
int dis[2002];
int vis[2002];
char str[2002][8];
int n,ans;
int wgh(int i,int j){
	int w=0,k;
	for(k=0;k<8;k++){
		if(str[i][k]!=str[j][k])
		w++;
	}
	return w;
}
void prim(){
	int i,j;
	ans=0;
	
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)
		dis[i]=INF;
	dis[1]=0;
	for(i=1;i<=n;i++){
		int index=-1,min=INF;
		for(j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<min){
				min=dis[j];
				index=j;
			}
		}
		vis[index]=1;
		ans+=dis[index];
		for(j=1;j<=n;j++){
			dis[j]=dis[j]>map[index][j]?map[index][j]:dis[j];
		}
	} 
}

int main(){
	int i,j;
	while(cin>>n&&n!=0){
		for(i=1;i<=n;i++)
		cin>>str[i];
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++){
				if(i==j)map[i][j]=0;
				else map[i][j]=map[j][i]=wgh(i,j);
			}
			prim();
		printf("The highest possible quality is 1/%d.\n",ans);	
	}
	return 0;
}
