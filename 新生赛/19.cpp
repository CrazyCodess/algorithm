#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char start;
	int w[3];
	int b[3];
	int flag;
	int cnt;
	while(cin>>start){
		scanf("%d%d%d",&w[0],&w[1],&w[2]);
		scanf("%d%d%d",&b[0],&b[1],&b[2]);
		flag=1;
		cnt=0;
		if(start=='W'){
			while(true){
				if(w[1]-b[2]<0){
					flag=0;
					break;
				}
				else if(b[1]-w[2]<0){
					flag=1;
					break;
				}
				
				
				if(w[1]-b[2]>0){
					b[0]-=w[1]-b[2];
					if(b[0]<=0){
						flag=1;
						break;
					}
					cnt++;
				}
				if(b[1]-w[2]>0){
					w[0]-=b[1]-w[2];
					if(w[0]<=0){
						flag=0;
						break;
					}
				}
				
				if(cnt>10000){
					flag=0;
					break;
				}
			}
		}
		else if(start=='B'){
			
			
			
			while(true){
				if(w[1]-b[2]<0){
					flag=0;
					break;
				}
				else if(b[1]-w[2]<0){
					flag=1;
					break;
				}		
						
				if(b[1]-w[2]>0){
					w[0]-=b[1]-w[2];
					if(w[0]<=0){
						flag=0;
						break;
					}
				}
				if(w[1]-b[2]>0){
					b[0]-=w[1]-b[2];
					if(b[0]<=0){
						flag=1;
						break;
					}
					cnt++;
				}
				if(cnt>10000){
					flag=0;
					break;
				}
			}
		}
		
		if(flag)printf("Warrior wins\n");
		else printf("Warrior loses\n");
	}
	return 0;
}
