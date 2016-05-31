#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip> 
using namespace std;
int main(){
	float f,s;
	s=0.0;
	for (int i = 0; i < 12; ++i)
	{
		scanf("%f",&f);
		s+=f;
	}
	printf("$%.2f\n",s/12 );
	//cout<<fixed<<setprecision(2)<<'$'<<s/12.0<<endl; 
	return 0;

}