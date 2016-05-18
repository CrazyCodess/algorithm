#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define M 100000007
int n;
long int ans;
int vis[1005],g[1005],f,buf[1005];
void swap(int a,int b){
	int temp=a;
	a=b;
	b=temp;
}

int gcd(int a,int b){
	int t;
	if(a<b)swap(a,b);
	while(b!=0){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int ggcd(){
	int i;
	int c=gcd(g[buf[0]],g[buf[1]]);
	for(i=2;i<f;i++){
		c=gcd(c,g[buf[i]]);
	}
	
	return c;
}

void dfs(int num){
	int i
	if(num==f){
		ans+=ggcd();
		ans%=M;
	}
	for(i=num;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(num+1);
			vis[i]=0;
		}
	}
}
int main(){
	int t,i; 
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&g[i]);
			ans+=g[i];
			ans%=M;
		}
			
		memset(vis,0,sizeof(vis));
		ans=0;
		dfs(0);
	}
	return 0;
}
