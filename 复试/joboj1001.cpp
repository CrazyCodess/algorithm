#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int m,n;
	int a[12][12],b,c[12][12],rows,cols;
	while(scanf("%d",&m)!=EOF&&m!=0){
		scanf("%d",&n);
		rows=0;
		cols=0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&a[i][j]);
			}
			
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&b);
				c[i][j]=a[i][j]+b;
			}
			
		}
		bool fr,fl;
		for (int i = 0; i < m; ++i)
		{	
			fr=true;
			for (int j = 0; j < n; ++j)
			{
				if(c[i][j]!=0&&fr)fr=false;
				
			}
			if(fr)rows++;
			
		
		}

		for (int i = 0; i < n; ++i)
		{	
			
			fl=true;
			for (int j = 0; j < m; ++j)
			{
			
				if(c[j][i]!=0&&fl)fl=false;
			}
			if(fl)rows++;
			
		
		}
		printf("%d\n",rows+cols );

	}
	return 0;
}