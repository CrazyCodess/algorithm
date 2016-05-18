#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll seq[100005],seq1[100005];
ll ans;
int main(){
	int t,n,i,j;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lld",&seq[i]);
		}
		for(i=0;i<n-1;i++){
			scanf("%lld",&seq1[i]);
		}
		sort(seq,seq+n);
		sort(seq1,seq1+n-1);
		for(i=0;i<n-1;i++){
			if(seq[i]!=seq1[i]){
				ans=seq[i];
				break;
			}
		}
		if(i>=n-1)
		ans=seq[n-1];
		printf("%lld\n",ans);
	}
	return 0;
	
}
