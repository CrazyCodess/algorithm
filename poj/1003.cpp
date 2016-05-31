#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int i;
	double f,s;
	while(scanf("%lf",&f)!=EOF&&f!=0.00){
		s=0.0;
		for ( i = 2; s < f; ++i)
		{
			s+=1.0/i;

		}
		printf("%d card(s)\n", i-2);
	}
	return 0;
}