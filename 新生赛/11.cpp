#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char lower(char a){
	if(a<97)return (char)((int)a+32);
	else return a;
}
int main(){
	int n,i,j,ans;
	string s[102];
	int f[102];
	while(scanf("%d",&n)!=EOF){
		memset(f,0,sizeof(f));
		ans=0;
		for(i=0;i<n;i++)
			cin>>s[i];
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(s[i].size()==s[j].size()){
					
				
				int length=s[i].size();
				int k,num=0;
				for(k=0;k<length;k++){
					if(lower(s[i].at(k))==lower(s[j].at(k))){
						num++;
					}
				}
				if(num>2){
					if(f[i]==0)ans++;
					 if(f[j]==0)ans++;
					f[i]=f[j]=1;
				}
				}
				
			}
		}
		printf("%d\n",ans);	
	} 
	return 0;
}

