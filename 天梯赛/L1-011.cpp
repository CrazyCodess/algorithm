#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	char str1[10005],str2[10005];
	int len1,len2,f[10005],i,j;
	memset(f,1,sizeof(f));
	gets(str1);
	//getchar();
	gets(str2);
	len1=strlen(str1);
	len2=strlen(str2);
	for ( i = 0; i < len1; ++i)
	{
		for ( j = 0; j < len2; ++j)
		{
			if(str1[i]==str2[j]){
				f[i]=0;
				break;
			}
		}
	}
	for ( i = 0; i < len1; ++i)
	{
		if(f[i])printf("%c", str1[i]);
	}
	printf("\n");

	//cout<<str1<<"&"<<str2<<endl;
	return 0;
}