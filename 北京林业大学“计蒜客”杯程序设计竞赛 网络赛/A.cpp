#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int t,n,n1,n2,m1,m2;
	long long cnt;
	scanf("%d",&t);
	while(t--){
		n1=n2=0;
		m1=m2=0;
		cnt=0;
		scanf("%d",&n);
		cnt+=n;
		n1=n/3;
		n2=n/4;
		m1=n-n1*3;
		m2=n-n2*4;
		//printf("n1=%d m1=%d n2=%d m2=%d\n",n1,m1,n2,m2);
		while(n1>0||n2>0){
			cnt+=n1;
			cnt+=n2;
			int temp1,temp2;
			temp2=n1+n2+m2;
			temp1=n1+n2+m1;
			n1=temp1/3;
			//printf("n1=%d n1+n2+m1=%d\n",n1,n1+n2+m1);
			m1=temp1-n1*3;
			n2=temp2/4;
			m2=temp2-n2*4;
			//printf("n1=%d m1=%d n2=%d m2=%d\n",n1,m1,n2,m2);
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
