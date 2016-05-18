#include<iostream>
#include<cstring>
#include<cmath>
#include<stdlib.h>
using namespace std;
double d[102][102];
double co[102][2];
double min_k[102];
int cmp( const void *a , const void *b )

{ return *(double *)a > *(double *)b ? 1 : -1; }

int main(){
	int t,m,n,i,j;
	while(cin>>t){
		while(t--){
			int min,tmin;
			memset(co,0,sizeof(co));
			cin>>m>>n;
			
			for(i=0;i<m;i++){
				cin>>co[i][0]>>co[i][1];
			}
			if(n>m){
				cout<<-1<<endl;
				continue;
			}
			for(i=0;i<m;i++)
				for(j=i;j<m;j++){
					d[j][i]=d[i][j]=sqrt((co[i][0]-co[j][0])*(co[i][0]-co[j][0])+(co[i][1]-co[j][1])*(co[i][1]-co[j][1]));
				}	
			for(i=0;i<m;i++){
				qsort(d[i],m,sizeof(d[0][0]),cmp);
			}	
			tmin=10000;
			min=-1;
			for(i=0;i<m;i++){
				min=(int)(d[i][n-1])+1;
				double temp=min*1.0;
				if(n<m){
					if(d[i][n]<=temp){
						min=-1;
					}
				}
				if(min!=-1){
					if(tmin>min)tmin=min;
				}
			}
			if(tmin==10000)
				cout<<-1<<endl;
			else 
			cout<<tmin<<endl;
		}
	}
	return 0;
}
