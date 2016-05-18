#include<iostream>
#include<cstdio>
using namespace std;
int pre[30005];
int rank[30005];
void makeset(){
	int i;
	for(i=0;i<30005;i++){
		pre[i]=i;
	}
}
int find(int x){
	if(x!=pre[x]){
		pre[x]=find(pre[x]);
		
	}
}
void uniun(int x,int y){
	
}
int main(){
	int p,a,b;
	char c;
	scanf("%d",&p);
	makeset();
	while(p--){
		cin>>c;
		if(c=='M'){
			scanf("%d%d",&a,&b);
			
		}
		else if(c=='C')
	}
	return 0;
}
