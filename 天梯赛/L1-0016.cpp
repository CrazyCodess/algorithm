#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char z[11]={'1', '0', 'X', '9' ,'8' ,'7', '6', '5', '4', '3', '2' };
int w[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int main(){
	char num[101][19];
	int n,i,j,f,sum;
	scanf("%d",&n);
	f=1;
	int f1=0;
	for (i = 0; i < n; ++i)
	{
		scanf("%s",num[i]);
	}
	for ( i = 0; i < n; ++i)
	{
		f1=0;
		sum=0;
		for (int j = 0; j < 17; ++j)
		{
			if(!(num[i][j]>='0'&&num[i][j]<='9')){
				printf("%s\n",num[i] );
				f=0;
				f1=1;
				break;
			}
			sum+=(num[i][j]-'0')*w[j];
		}
		if(!f1){
			if(z[sum%11]!=num[i][17]){
				printf("%s\n",num[i] );
				f=0;
			}
		}
	}
	if(f){
		printf("All passed\n");
	}

	return 0;
}