#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct point{
	int x,y,z;
}p[182];
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	p[0]={x,y,z};
	cout<<p[0].x<<p[0].y<<p[0].z<<endl;
	return 0;
}