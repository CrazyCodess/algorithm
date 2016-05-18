#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int flag[26][2];
int main(){
	int t,i,j,f;
	string str1,str2;
	char s1[1002],s2[1002]; 
	scanf("%d",&t);
	while(t--){
		memset(flag,0,sizeof(flag));
		cin>>str1>>str2;
		for(i=0;i<str1.length();i++){
			flag[(int)str1.at(i)-97][0]=1;
		}
		for(i=0;i<str2.length();i++){
			flag[(int)str2.at(i)-97][1]=1;
		}		
		f=true;
		for(i=0;i<26;i++){
			if(flag[i][0]!=flag[i][1]){
				f=false;
				break;
			}
		}
		if(!flag){
			printf("No\n");
			continue;
		}
		int len1,len2;
		len1=str1.length();
		len2=str2.length();
		for(i=0;i<len1-1;){
			if(str1.at(i)==str1.at(i+1)){
				str1.erase(i,1);
				len1=str1.length();
			}
			else{
				i++;
			}
		}
		for(i=0;i<len2-1;){
			if(str2.at(i)==str2.at(i+1)){
				str2.erase(i,1);
				len2=str2.length();
			}
			else{
				i++;
			}
		}		
		memset(s1,'\0',sizeof(s1));
		memset(s2,'\0',sizeof(s2));
		for(i=0;i<str1.length();i++){
			s1[i]=str1.at(i);
		}
		for(i=0;i<str2.length();i++){
			s2[i]=str2.at(i);
		}		
		if(strcmp(s1,s2)==0)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
