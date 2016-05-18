#include<iostream>
#include<cstdio>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> vect;
int main(){
	int a,i;
	while(scanf("%d",&a)){
		if(a==-1)break;
		if(a==0){
			//vect.push_back(a);
			vector<int>::iterator new_end;
			new_end=unique(vect.begin(),vect.end());
			printf("s=%d",vect.size());
			vect.erase(new_end,vect.end());
			printf("s1=%d",vect.size());
				 for(i=0;i<vect.size();i++){
				 	printf("%d ",vect.at(i));
				 }			
			printf("\n");
			vect.clear();
			continue;
		}
		vect.push_back(a);
	}
	return 0;
}
