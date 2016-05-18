#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	int a,b,c;
	int num,num1,v;
	while(scanf("%d",&n)!=EOF){
		scanf("%d%d%d",&a,&b,&c);
		num=0;
		num1=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&v);
			v+=num1;
			num1=0;
			if(v>=a&&v<b)num+=2;
			else if(v>=b&&v<c)num+=3;
			else if(v>=c)num+=4;
			else if(v<a)num1+=v;
		} 
		printf("%d\n",num);
	}
	return 0;
}
