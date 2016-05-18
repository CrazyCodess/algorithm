#include <iostream>
#include<cstdio>
#include <cmath>
using namespace std;
int main(){
	int t;
	int x1,y1,r1,x2,y2,r2;
	int d,l;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2);
			if(x1==x2&&y1==y2&&r1==r2){
				printf("-1\n");
			}
			else{
				d=r1+r2;
				l=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
				if(l>d)printf("4\n");
				else if(l==d)printf("3\n");
				else if(l<d){
					if(r1<r2){
						if(l+r1<r2){
							printf("0\n");
						}
						else if(l+r1==r2){
							printf("1\n");
						}
						else if(l+r1>r2){
							printf("2\n");
						}
					}
					else if(r1>r2){
						if(l+r2<r1){
							printf("0\n");
						}
						else if(l+r2==r1){
							printf("1\n");
						}
						else if(l+r2>r1){
							printf("2\n");
						}
					}
					else if(r1==r2){
						printf("2\n");
					}
				}
			}
		}
	}
	return 0;
} 
