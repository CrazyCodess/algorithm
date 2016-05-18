/*ÊýËþ*/
#include<iostream>
using namespace std;
int d[102][102];
int n=0;
int maxDp(int a,int b){
	return a>b?a:b;
}
void dp(int i,int j){
	if(i==0&&j==0)return ;
	if(j==0)d[i][j]+=d[i-1][j];
	else if(i==j)d[i][j]+=d[i-1][j-1];
	else{
		d[i][j]+=maxDp(d[i-1][j-1],d[i-1][j]);
	}
}
int main(){
	int c,i,j,max;
	while(cin>>c){
		while(c--){
			cin>>n;
			for(i=0;i<n;i++)
				for(j=0;j<=i;j++){
					cin>>d[i][j];
					dp(i,j);
				}
			max=d[0][0];
			for(i=0;i<n;i++)
				if(d[n-1][i]>max)max=d[n-1][i];
			cout<<max<<endl;
		}
	}
	return 0;
}
