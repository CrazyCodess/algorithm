#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
	int p,t,g1,g2,g3,gj;
	float ans,diff;
	while(scanf("%d",&p)!=EOF){
		ans=0.0;
		scanf("%d%d%d%d%d",&t,&g1,&g2,&g3,&gj);
		diff=abs(g1-g2);
		if(diff<=t*1.0){
			ans=(g1+g2)*1.0/2;

		}
		else if(abs(g1-g3)<abs(g2-g3)&&abs(g1-g3)<=t*1.0){
			ans=(g3+g1)*1.0/2;	
		}
		else if(abs(g2-g3)<abs(g1-g3)&&abs(g2-g3)<=t*1.0){
			ans=(g3+g2)*1.0/2;	
		}
		else if(abs(g1-g3)<=t&&abs(g2-g3)<=t*1.0){
			if(g1<=g2){
				if(g2>=g3)
				ans=g2*1.0;
				else ans=g3*1.0;
			}
			else {
				if(g1>=g3)
				ans=g1*1.0;
				else ans=g3*1.0;
			}

		}
		else{
			ans=gj*1.0;
		}
		printf("%.1f\n",ans );
	}
	return 0;
}