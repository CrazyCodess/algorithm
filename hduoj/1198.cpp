#include<iostream>
#include<cstdio>
using namespace std;
int map[555][555];
int n,m;
int pre[555*555];
int cnt;
int linked[11][4]={{1,0,0,1},{1,1,0,0},{0,0,1,1},
					{0,1,1,0},{1,0,1,0},{0,1,0,1},
					{1,1,0,1},{1,0,1,1},{0,1,1,1},
					{1,1,1,0},{1,1,1,1}
					};
void makeset(){
	int i;
	for(i=0;i<m*n;i++){
		pre[i]=i;
	}
	cnt=m*n;
	return;
}
int find(int x){
	if(x!=pre[x]){
		pre[x]=find(pre[x]);
	}
	return pre[x];
} 
void uniun(int a,int b){
	if(find(b)!=find(a)){
		pre[find(b)]=find(a);
		cnt--;
	}
}
void count(int x1,int y1,int x2,int y2,bool r){
	if(x2>m-1||y2>n-1)return;
	bool mark=false;
	//cout<<mark<<endl;
	if(r){
		if(linked[map[x1][y1]][1]&&linked[map[x2][y2]][3])mark=true;
	}
	else{
		if(linked[map[x1][y1]][2]&&linked[map[x2][y2]][0])mark=true;
	}
	//cout<<mark<<endl;
	if(mark){
		
		uniun(x1*n+y1,x2*n+y2);
		//uniun((x1-1)*m+y1,(x2-1)*m+y2);
		//printf("%d\n",cnt);	
		//cnt--;
	}
	return;	
}
int main(){
	int i,j;
	char c;
	while(scanf("%d%d",&m,&n)){
		if(n==-1&&m==-1)break;
		makeset();
		for(i=0;i<m;i++)
			for(j=0;j<n;j++){
				cin>>c;
				map[i][j]=c-'A';		
			}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++){
				//printf("map=%d ",map[i][j]);
				count(i,j,i+1,j,false);
				count(i,j,i,j+1,true);		
			}
		printf("%d\n",cnt);
	}	
	return 0;
} 
