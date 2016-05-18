#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char map[12][12];
int main(){
	int t,n,m,k,x,y,i,j;
	scanf("%d",&t);
	while(t--){
		memset(map,'0',sizeof(map));
		scanf("%d%d%d",&n,&m,&k);
		for(i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			map[x][y]='M';
			if(y+1<=m){
				if(x-1>=1&&map[x-1][y+1]!='M')map[x-1][y+1]=(char)(map[x-1][y+1]+1);
				if(x+1<=n&&map[x+1][y+1]!='M')map[x+1][y+1]=(char)(map[x+1][y+1]+1);
				
				if(map[x][y+1]!='M')
				map[x][y+1]=(char)(map[x][y+1]+1);
			}
			if(y-1>=1){
				if(x-1>=1&&map[x-1][y-1]!='M'){
					map[x-1][y-1]=(char)(map[x-1][y-1]+1);

				}
				if(x+1<=n&&map[x+1][y-1]!='M'){
					map[x+1][y-1]=(char)(map[x+1][y-1]+1);

				}
				if(map[x][y-1]!='M')
				map[x][y-1]=(char)(map[x][y-1]+1);
				

			}
				if(map[x+1][y]!='M'&&x+1<=n)
					map[x+1][y]=(char)(map[x+1][y]+1);
				if(map[x-1][y]!='M'&&x-1>=1)
				map[x-1][y]=(char)(map[x-1][y]+1);

			
		}
		
		for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(map[i][j]=='0')printf(".");
					else{
						printf("%c",map[i][j]);
					}
				}	
				printf("\n");
			}
			printf("\n");
	}
	return 0;
} 


