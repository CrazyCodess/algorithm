#include<iostream>
#include<cstdio>
using namespace std;
int maxk[10005],index;
void update(int value){
	int a=0,b=index-1,mid,i;
	i=index;
	while(a<=b){
		mid=(a+b)/2;
		if(maxk[mid]<value){
			b=mid-1;
			if(i>mid)
			i=mid;
		}
		else if(maxk[mid]>value){
			a=mid+1;
		}
		else if(maxk[mid]==value){
			i=mid;
			break;
		}
	}
	maxk[i]=value;
	
}

int main(){
	int t,n,value;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		index=0;
		while(n--){
			scanf("%d",&value);			
			if(index==0||maxk[index-1]>value){
				maxk[index]=value;
				index++;
			}
			else{
				update(value);
			}
		}
		printf("%d\n",index);
	}
	return 0;
}
