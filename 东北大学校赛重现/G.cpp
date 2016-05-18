#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int t,i,j,cnt,k;
	scanf("%d",&t);
	char a[5005];
	char b[5005];
	while(t--){
		scanf("%s",a);
		scanf("%s",b);
		cnt=0;
		int temp=0;
		for(i=0;a[i]!='\0';i++){
			k=i;
			temp=0;
			for(j=0;b[j]!='\0';j++){
				if(a[k]==b[j]){
					temp++;
					k++;
				}
			}
			if(temp>cnt)cnt=temp;
		}
		printf("%d\n",cnt);	
	}
	return 0;
}
