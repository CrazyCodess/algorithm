#include<iostream>
#include<cstdio>
using namespace std;
string z[1005];
int kao[1005];
int main(){
	int n,i,m,a,b,q;
	string temp;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			cin>>temp;
			scanf("%d%d",&a,&b);
			kao[a]=b;
			z[a]=temp;
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d",&q);
			cout<<z[q]<<" "<<kao[q]<<endl;
			//printf("%s %d\n",z[q],kao[q]);	
		}
	}
	return 0;
}
