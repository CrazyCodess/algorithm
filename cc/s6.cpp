#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int t;
	string s;
	long int i,j,ans,length,index,k;
	int flag=1;
	while(cin>>t){
		for(i=1;i<=t;i++){
			cin>>s;
			length=s.length();
			ans=0;
			k=0;
			flag=1;
			while(k<length){
			if(s.at(k)=='f')k++;
			else break;}
			if(k==length){cout<<"Case #"<<i<<": "<<(s.length()/2)+s.length()%2<<endl;continue;}
			
			index=s.find_first_of('c',0);
			if(index==-1) cout<<"Case #"<<i<<": "<<-1<<endl;
			else{
				
			for(j=index;j<length;){
				if(s.at(j)=='c'||s.at(j)=='f'){
					
				
				if(s.at(j)=='c'){
					if(s.at((j+1)%length)=='f'&&s.at((j+2)%length)=='f'){
						j=(j+1)%length;
						while(s.at(j)=='f'){
							j=(j+1)%length;
							
						}
							
						ans++;
						
					}
					else{
						flag=0;
						break;
					}
				}
				else j++;
				if(j==index)break;
				}
				else {
					flag=0;break;
				}
			}
			if(ans==0&&flag==1){
				ans+=(s.length()/2)+s.length()%2; 
			}
			if(flag==0)cout<<"Case #"<<i<<": "<<-1<<endl;
			else
			cout<<"Case #"<<i<<": "<<ans<<endl;
			}
			
			
			 
		}
	}
	return 0;
}
