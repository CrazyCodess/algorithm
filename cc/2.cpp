#include<iostream>
#include<cstring>
using namespace std;
long int ponds[10004];
int pipe[10001][10001];
int d[10004];
int main(){
	int t,p,m,i,a,b,j;
	long long sum;
	while(cin>>t){
		while(t--){
			sum=0;
			memset(ponds,0,sizeof(ponds));
			memset(pipe,0,sizeof(pipe));
			memset(d,0,sizeof(d));
			cin>>p>>m;
			for(i=1;i<=p;i++)
				cin>>ponds[i];
				
			for(i=1;i<=m;i++){
				cin>>a>>b;
				d[a]++;
				d[b]++;
				pipe[a][b]=1;
				pipe[b][a]=1;
			}
			for(i=1;i<=p;i++){
				for(j=1;j<=p;j++){
					if()
				}
			}
				
			for(i=1;i<=p;i++){
				if(pipe[i]!=0)sum+=ponds[i];
			}
			cout<<sum<<endl;
		}
	}
}