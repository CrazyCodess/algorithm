#include<iostream>
using namespace std;

int main(){
	int den[23][23];
	int d[17];
	int days,n,i,j,l,k[21][21];
	for(i=0;i<=21;i++)
		for(j=0;j<=21;j++)
		den[i][j]=0;
	while(cin>>n){
		while(n--){
			cin>>days;
			for(i=0;i<16;i++)
			cin>>d[i];

			for(i=1;i<=20;i++)
				for(j=1;j<=20;j++)
					cin>>den[i][j];
			for(i=1;i<=days;i++){
				for(j=1;j<=20;j++)
					for(l=1;l<=20;l++)
						k[j][l]=den[j][l]+den[j-1][l]+den[j+1][l]+den[j][l-1]+den[j][l+1];
						for(j=1;j<=20;j++)
							for(l=1;l<=20;l++){
							den[j][l]+=d[k[j][l]];
							if(den[j][l]>3)den[j][l]=3;
							if(den[j][l]<0)den[j][l]=0;
							}
					
			}
			
		for(i=1;i<21;i++){
			for(j=1;j<21;j++){
				if(den[i][j]==0)cout<<'.';
				else if(den[i][j]==1)cout<<'!';
				else if(den[i][j]==2)cout<<'X';
				else if(den[i][j]==3)cout<<'#';
			}	
				cout<<endl;
			}
		
			if(n!=0)cout<<endl;
		}
		
	}
	
} 