#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char temp[17];
char tel[100005][8];
int main(){
	int n,i,j,len,k;
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		len=0;
		cin>>temp;
		len=strlen(temp);
		k=0;
		for(j=0;j<len;j++){
			if(temp[j]=='-'||temp[j]==81||temp[j]==90)continue;
			if(temp[j]>=65&&temp[j]<90){
				switch(temp[j]){
					case 'A':
					case 'B':
					case 'C':temp[j]='2';break;
					case 'D':
					case 'E':
					case 'F':temp[j]='3';break;
					case 'G':
					case 'H':
					case 'I':temp[j]='4';break;
					case 'J':
					case 'K':
					case 'L':temp[j]='5';break;
					case 'M':
					case 'N':
					case 'O':temp[j]='6';break;
					case 'P':
					case 'R':
					case 'S':temp[j]='7';break;
					case 'T':
					case 'U':
					case 'V':temp[j]='8';break;
					case 'W':
					case 'X':
					case 'Y':temp[j]='9';break;
				}
			}
			tel[i][k]=temp[j];
			k++;
		}
	}



	for ( i = 0; i < n; ++i)
	{
		cout<<tel[i]<<endl;
	}
	return 0;

}