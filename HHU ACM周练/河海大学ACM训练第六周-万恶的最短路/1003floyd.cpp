#include<iostream>
#include<cstring> 
using namespace std;
#define MAX 999999999;
int map[101][101];
int n;
void floyd(){
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(map[i][j]>map[i][k]+map[k][j])map[i][j]=map[i][k]+map[k][j];
			}
}
int main(){
	int i,j,k,k1,b,p,length,ans;
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
			floyd();	
		ans=0;
		for(i=1;i<=n;i++){
			if(ans<map[1][i])ans=map[1][i]; 
		}
		cout<<ans<<endl;
	}
	return 0;
}
