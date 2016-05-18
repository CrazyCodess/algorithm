#include<iostream>
#include<cstdio>
#include <algorithm>
#include<cstdlib>
using namespace std;
struct node{
	long int value;
	int book;
}a[10003];

int comp(node c,node b)
{
return c.value<b.value;
}
int main(){
	int t;
	scanf("%d",&t);
	int n,m;
	long int k;
	long int sum;
	int count;

	while(t--){
		scanf("%d%d%ld",&n,&m,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&(a[i].value));
		}
		sum=0;
		count=0;
		for(int i=0;i<m;i++){
			int temp;
			scanf("%d",&temp);
			temp=temp-1;
			a[temp].book=1;
			sum+=a[temp].value;
			count++;
		}
		if(sum>k)cout<<"-1"<<endl;
		else{
			sort(a,a+n,comp);
			int i=0;
			while(sum<k&&i<n){
				if(a[i].book==0&&(a[i].value<=(k-sum))){
					sum+=a[i].value;
					count++;
					
				}
				i++;
			}
			cout<<count<<endl;
		}
	}

	return 0;
}
