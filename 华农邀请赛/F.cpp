#include<iostream>
#include<cstdio>
using namespace std;
int ch[105];
int main(){
	int t,n,i,j,min;
	scanf("%d",&t);
	while(t--){
		
		scanf("%d",&n);
		min=999;
		for(i=0;i<n;i++)
			scanf("%d",&ch[i]);
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(ch[i]==ch[j]){
					if(j-i<min)min=j-i;
					break;
				}
			}
		}
		printf("%d\n",min);
	}
	return 0;
}
