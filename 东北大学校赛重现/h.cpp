#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a;
int t,n,m,i,j;
string op,str;
int num1,num2,num3
int main(){	

	
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			str.append(i-2,a+48);
		}
		for(i=1;i<=m;i++){
			cin>>op;
			char c=op.at(0);
			if(c=='C'){
				scanf("%d%d%d",&num1,&num2,&num3);
			}
			else if(c=='D'){
				scanf("%d",&num1);
			}
			else{
				
			}
			switch(op.at(0)){
				case 'C':
			}
		}
	}
	return 0;
}
