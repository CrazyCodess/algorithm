#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	char max='a',c;
	int i,j;
	long int len;
	while(cin>>s){
		max=s[0];
		for(i=0;i<s.length();i++)
			if(max<s[i])
				max=s[i];
			
		
	 	len=s.length();
		for(i=0;i<len;){
			if(s[i]>=max){
				s.insert(i+1,"(max)");
				len=len+5;
				i=i+6;	
			}
			else i++;
		}
		cout<<s<<endl;
	}

	return 0;
}
