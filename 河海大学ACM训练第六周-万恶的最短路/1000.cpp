#include<iostream>
using namespace std;
int edge[101][101];
int d[101];
#define MAX 999999;
int n;
int final[101];
int query_shortPath(int v0){
	int v,w;
	for(v=1;v<=n;v++){
		final[v]=0;d[v]=edge[v0][v];
	}
	d[v0]=0;final[v0]=1;
	for(int i=1;i<n;i++){
		int min=MAX;
		for(w=1;w<=n;w++){
			if(!final[w]){
				if(d[w]<min){
					v=w;
					min=d[w];
				}
			}
		}
		final[v]=1;
		for(w=1;w<=n;w++){
			if(!final[w]&&(min+edge[v][w])<d[w]){
				d[w]=min+edge[v][w];
			}
		} 
	}
	int max=d[v0];
	for(v=1;v<=n;v++){
		if(max<d[v])max=d[v];
	} 
	return max;
}
int main(){
	int num,i,j,a,k;
	int min,temp,v,s;
	final[0]=0;
	while(cin>>n&&n!=0){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				if(i==j)edge[i][j]=0;
				else 
				edge[i][j]=MAX;
		}
		for(j=1;j<=n;j++){
			cin>>num;
			for(i=1;i<=num;i++){
				cin>>a>>s;
				edge[i][a]=s;
			}
		}
		min=MAX;
		v=1;
		for(i=1;i<=n;i++){
			temp=query_shortPath(i);
			if(min>temp){min=temp;v=i;}
		}
		cout<<v<<" "<<min<<endl;
	}
	return 0;
} 
