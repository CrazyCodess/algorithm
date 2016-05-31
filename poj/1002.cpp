#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
char temp[128];
int tel[10000000];
int tem;
int f;
int num[] =   
{  
    2, 2, 2,  
    3, 3, 3,  
    4, 4, 4,  
    5, 5, 5,  
    6, 6, 6,  
    7, 0, 7, 7,  
    8, 8, 8,  
    9, 9, 9  
};  
//map<int ,int> tel;
int main(){
	int n,i,j,len,cnt;
	memset(tel,0,sizeof(tel));
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		len=0;
		scanf("%s",temp);
		//cin>>temp;
		len=strlen(temp);
		tem=0;
		for(j=0;j<len;j++){
			
			if((temp[j]>='A'&&temp[j]<'Z'&&temp[j]!='Q')||(temp[j]>='0'&&temp[j]<='9')){
				if (temp[j]>='A'&&temp[j]<'Z')
				{
					
					tem=tem*10+num[temp[j]-'A'];
				}
				else
				tem=tem*10+temp[j]-'0';
			}


		}

		tel[tem]++;
		//tel[tem]++;
	}

	f=0;
/*	for(map<int, int>::iterator it = tel.begin(); it != tel.end(); it++)
		if(it->second > 1)
		{
			f = true;
			printf("%03d-%04d %d\n", it->first / 10000, it->first % 10000, it->second);
		}*/
	for ( i = 0; i <= 9999999; ++i)
			{
				if(tel[i]>1){
					f=1;
					printf("%03d-%04d %d\n", i/10000, i%10000, tel[i]);
				}
			}		
	if(!f)
		puts("No duplicates.\n");
	return 0;

}