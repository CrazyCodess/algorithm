#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t;
	double k,l,r,temp,n;
	while(cin>>t)
	{
		while(t--){
			cin>>k;
			temp=2.0/(1-2k);
			l=log10(temp)/log10(2)-1;
			r=l+1;
			n=(int)r;
			if(k==)
		}
	}
}

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	double arr[T];
	double brr[T];
	int x=-1;
	for(int i=0;i<T;i++)
	{
		scanf("%lf",&arr[i]);
		brr[i]=log(0.5-arr[i])/log(0.5);
		if(brr[i]==(int)brr[i]) printf("%d\n",x);
		else printf("%d\n",4*(int)brr[i]);
	}
	return 0;
}