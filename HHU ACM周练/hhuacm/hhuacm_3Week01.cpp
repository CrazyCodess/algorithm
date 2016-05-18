/*
¶þ²æËÑË÷Ê÷ 
*/
#include<iostream>
#include<cstring>
#include <cstdio>
using namespace std;
int main(){
	int n,i,j;
	int c;
	int tree[1026]; 
	int tree1[1026];
	string s;
	while(cin>>n&&n){
		cin>>s;
		memset(tree,-1,sizeof(tree));
		for(i=0;i<s.size();i++){
			c=s[i]-'0';
			j=1;
			while(tree[j]!=-1){
				if(c<tree[j])j=j*2;
				else if(c>tree[j])j=j*2+1;
			}
			tree[j]=c;
		}
		
		while(n--){
			cin>>s;
			memset(tree1,-1,sizeof(tree1));
			for(i=0;i<s.size();i++){
				c=s[i]-'0';
				j=1;
				while(tree1[j]!=-1){
					if(c<tree1[j])j=j*2;
					else if(c>tree1[j])j=j*2+1;
				}
				tree1[j]=c;				
			}
			for(i=1;i<=1024&&tree[i]==tree1[i];i++);
			if(i>1024)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
