#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int comb(int n,int m){//求组合数C(n,m) 
	if(m==0||n==m)return 1;
	if(m==1)return n;
	int i,sum1=1,sum2=1;
	for(i=1;i<=m;i++)sum1*=i;
	for(i=n-m+1;i<=n;i++)sum2*=i;
	return sum2/sum1;
}
int main(){
	int n,sum,i,cnt;
	int a[20],s[20];
	while(scanf("%d %d",&n,&sum)!=EOF){
		for(i=0;i<n;i++){
			if(i>(n-1)/2){
				s[i]=s[n-1-i];
			}
			else{
				s[i]=comb(n-1,i);
			}
		}
		
		for(i=0;i<n;i++)a[i]=i+1;
		do{
			cnt=0;
			for(i=0;i<n;i++){
				cnt+=a[i]*s[i];
			}
			if(cnt==sum){
				for(i=0;i<n-1;i++)printf("%d ",a[i]);
				printf("%d\n",a[n-1]);
				break;
			}
		}while(next_permutation(a,a+n));
		
	}	
	return 0;
}
