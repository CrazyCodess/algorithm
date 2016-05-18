#include<iostream>
#include<cstring> 
using namespace std;
#define MAX 999999;
int map[101][101];
int n;
int minx(int a,int b){
	return a<b?a:b;
}
void floyd(){
	int i,j,k,s;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				map[i][j]=minx(map[i][k]+map[k][j],map[i][j]);
			}
}
int main(){
	int i,j,k,k1,b=0;
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
						for(k=s.length()-1,k1=0;k>=1&&k1<s.length();k--){
							b+=(int)(s.at(k1)-'0')*10*k;
							k1++;
						}	
						map[i][j]=map[j][i]=b;
					}
				}
				if(i==j)map[i][j]=0;
			}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
					cout<<map[i][j]<<" ";
				}
				cout<<endl;
		}

	}
	return 0;
}