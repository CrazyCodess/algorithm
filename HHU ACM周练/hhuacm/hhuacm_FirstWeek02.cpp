#include<iostream>
using namespace std;
int main(){
	char s[3],temp;
	while(cin>>s[0]){
		
		cin>>s[1]>>s[2];
		for(int i=0;i<3;i++){
			for(int j=i+1;j<3;j++){
			 	if(s[i]>s[j]){
	 				temp=s[i];
	 				s[i]=s[j];
	 				s[j]=temp;
	 			} 
			 } 
		}
		cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
	}
	return 0;
} 
