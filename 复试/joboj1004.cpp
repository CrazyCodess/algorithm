#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long int L1[1000100],L2[1000100],L3[1000100];
int main(){
	int n1,n2,s1,s2,t;
	while(scanf("%d",&n1)!=EOF){
		for (int i = 0; i < n1; ++i)
		{
			scanf("%ld",&L1[i]);
		}
		scanf("%d",&n2);
		for (int i = 0; i < n2; ++i)
		{
			scanf("%ld",&L2[i]);
		}		
		s1=s2=t=0;
		while(s1<n1&&s2<n2){
			if(L1[s1]<L2[s2])L3[t++]=L1[s1++];
			else L3[t++]=L2[s2++];
		}
		while(s1<n1)L3[t++]=L1[s1++];
		while(s2<n2)L3[t++]=L2[s2++];
		printf("%ld\n",L3[(0+t-1)/2] );
	}

	return 0;
}