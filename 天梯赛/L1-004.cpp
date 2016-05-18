#include <iostream>
#include <cmath>
#include<cstdio>
using namespace std;
int main(){
	int f,c;
	while(scanf("%d",&f)!=EOF){
		c=(int)5*(f-32)*1.0/9;
		printf("Celsius = %d\n",c);
	}
	return 0;
}
