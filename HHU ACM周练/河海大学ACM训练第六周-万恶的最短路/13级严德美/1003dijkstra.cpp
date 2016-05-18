/*
求出从第一个点到任意点最短距离 
*/
#include<iostream>
using namespace std;
#define MAX 999999999;
int map[101][101];
int d[101];
int n;
int final[101];
int  dijktra(){
	int i,j,v,ans,min;
	for(i=1;i<=n;i++){
		final[i]=0;
		d[i]=map[1][i];
	}
	final[1]=1;
	for(i=1;i<n;i++){
		min=MAX;
		for(j=1;j<=n;j++){
			if(!final[j]){
				if(min>d[j]){
					v=j;
					min=d[j];
				}
				
			}
		}
		final[v]=1;
		for(j=1;j<=n;j++){
			if(!final[j]&&(min+map[v][j])<d[j]){
				d[j]=min+map[v][j];
			}
		}
	}
	ans=0;
	for(i=1;i<=n;i++){
		if(ans<d[i])ans=d[i];
	}
	return ans;
}
int main(){
	int i,j,k,k1,b,p,length;
	string s;
	while(cin>>n){
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++){
				if(i>1&&j<i){
					cin>>s;
					if(s.at(0)=='x'){
						map[i][j]=map[j][i]=MAX;
					}
					else{
						b=0;
						length=1;
						p=1;
						for(k=s.length()-1;k>=0;k--){
							b+=(int)(s.at(k)-'0')*p;
							p*=10;
						}	
						map[i][j]=map[j][i]=b;
					}
				}
				if(i==j)map[i][j]=0;
			}	

		cout<<dijktra()<<endl;
	}
	return 0;
}
