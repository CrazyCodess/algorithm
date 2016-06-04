#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n,cnt1,cnt2,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(a%2==0)cnt2++;
		else cnt1++;
	}
	printf("%d %d\n",cnt1,cnt2 );
	return 0;
}