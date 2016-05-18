/*
先求出任意两点之间的最短距离
然后任取一个点，求它到其余点距离的最大值
遍历所有点，取这些距离中最小的一个 
*/ 
#include<iostream>
using namespace std;
int map[101][101];
int n;
#define MAX 999999;
void shortPath_Floyd(){
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(map[i][j]>map[i][k]+map[k][j])map[i][j]=map[i][k]+map[k][j];
			}
}
int main(){
	int i,j,num,a,v,ans,s; 
	while(cin>>n&&n!=0){
		ans=MAX;
		v=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				map[i][j]=MAX;
			}
		for(i=1;i<=n;i++){
			cin>>num;
			for(j=1;j<=num;j++){
				cin>>a>>s;
				map[i][a]=s;
			}
		}
		shortPath_Floyd();
		for(i=1;i<=n;i++){
			int temp=0;
			for(j=1;j<=n;j++){
				if(i==j)continue;
				if(temp<map[i][j])temp=map[i][j];
			}
			if(ans>temp){
				v=i;
				ans=temp;
			} 
		}	
		cout<<v<<" "<<ans<<endl;
	}
	return 0;
}