#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int pre[100005];
int cnt;
int f[100005];
int max(int a,int b){
	return a>b?a:b;
}
void makeset(){
	int i;
	for(i=0;i<100005;i++){
		pre[i]=i;
		f[i]=0;
	}
		
	
}
int find(int x){
	if(x!=pre[x]){
		pre[x]=find(pre[x]);
	//	return x;
	}
	return pre[x];
}
void uniun(int x,int y){
	pre[y]=x;
}

int main(){
	int a,b,maxi,i,num;
	int flag=true;
	makeset();
	maxi=0;
	num=0;
	cnt=1;
	//freopen("input.txt","r",stdin); 
	while(scanf("%d%d",&a,&b)!=EOF){
		maxi=max(a,maxi);
		maxi=max(b,maxi);
		f[a]=f[b]=1;
		if(a==-1&&b==-1)break;
		if(a==0&&b==0){
		//	for(i=1;i<=maxi;i++){
				//if(pre[i]==i&&f[i])num++;
		//		printf("pre=%d ",pre[i]);
		//	}			
			if(flag){
				for(i=1;i<=maxi;i++){
					if(pre[i]==i&&f[i])num++;
				}
				//printf("true\n");
				if(num<=1)
				printf("Case %d is a tree.\n",cnt);
				//printf("Yes\n");
				else printf("Case %d is not a tree.\n",cnt);
				
			}
			else printf("Case %d is not a tree.\n",cnt);
			makeset();
			flag=true;
			maxi=0;
			num=0;
			cnt++;
			continue;
		}
		int fx=find(a);
		int fy=find(b);
	
		if(fx==fy){
			flag=false;
		}
		if(flag)
		uniun(fx,fy);	
						
		

		
	}
	return 0;
}
