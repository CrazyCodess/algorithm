#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define eps 1e-8
int main(){
	double n1,n2;
	scanf("%lf%lf",&n1,&n2);
	if (fabs(n1-n2)<=eps)
	{
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
	return 0;
}