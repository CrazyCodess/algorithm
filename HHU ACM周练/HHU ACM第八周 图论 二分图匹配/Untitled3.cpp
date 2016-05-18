#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n;
	int u,v,i,j,k;
	char str[100],a;
	while(scanf("%d",&n),n){
			//	memset(g,0,sizeof(g));
			a=getchar();
		for(k=0;k<n;k++){
			gets(str);
			u=str[0]-48;
			j=str[4]-48;
			cout<<u<<" "<<j<<" "<<endl;
		}
	}
	return 0;
}
