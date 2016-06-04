#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	char s[10010];
	int num[4];
	cin>>s;
	num[0]=num[1]=num[2]=num[3]=0;
	for (int i = 0; i < strlen(s); ++i)
	{
		if(s[i]>='A'&&s[i]<='Z')
			s[i]=s[i]-'A'+'a';
		if(s[i]=='g')num[0]++;
		else if(s[i]=='p')num[1]++;
		else if(s[i]=='l')num[2]++;
		else if(s[i]=='t')num[3]++;
	}
	while(num[0]+num[1]+num[2]+num[3]>0){
		if(num[0]>0){
			printf("G");
			num[0]--;
		}
		if(num[1]>0){
			printf("P");
			num[1]--;
		}
		if(num[2]>0){
			printf("L");
			num[2]--;
		}
		if(num[3]>0){
			printf("T");
			num[3]--;
		}
	}
	printf("\n");

	return 0;
}