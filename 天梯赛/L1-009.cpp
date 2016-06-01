#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long gcd(long long a,long long b){
	long long t;
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	
	while(b){
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}
long long mgcd(long long a,long long b){
	return a*b/gcd(a,b);
}

long long sub[105],den[105],ans[2],temp,mg;
int main(){
	int n,i,j,len,flag;
	char num[50];
	while((scanf("%d",&n)!=EOF)){
		memset(sub,0,sizeof(sub));
		memset(den,0,sizeof(den));
		for ( i = 0; i < n; ++i)
		{
			//scanf("%s",num);
			scanf("%lld/%lld",&sub[i],&den[i]);
			temp=gcd(sub[i],den[i]);
			sub[i]/=temp;
			den[i]/=temp;
		}
		ans[0]=sub[0];
		ans[1]=den[0];
		//printf("f=%d ",f[0] );
		for ( i = 1; i < n; ++i)
		{
			mg=mgcd(ans[1],den[i]);
			ans[0]=(ans[0]*mg)/ans[1]+(sub[i]*mg)/den[i];
			ans[1]=mg;
		}
		if(!ans[0]){
			printf("0\n");
			return 0;
		}
		//ans
		mg=0;
		//printf("%ld/%ld ",ans[0],ans[1] );	
		temp=ans[0]/ans[1];
		ans[0]-=temp*ans[1];
		mg=gcd(ans[0],ans[1]);
		ans[0]/=mg;
		ans[1]/=mg;
		if(temp){
			printf("%lld", temp);
			 if(ans[0])printf(" %lld/%lld",ans[0],ans[1]);
		}
		else{
			if(ans[0])printf("%lld/%lld",ans[0],ans[1]);
		}
		//mg=0;
/*		if(temp>0)mg=ans[0]%ans[1];
		if(temp>0)printf("%ld ", temp);
		if(ans[0]<ans[1])printf("%ld/%ld", ans[0],ans[1]);
		if(mg>0)printf("%ld/%ld", mg,ans[1]);*/

		//printf("%ld/%ld ",ans[0],ans[1] );	

		printf("\n");

	}
	return 0;
}