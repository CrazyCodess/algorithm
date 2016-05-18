/*¾ØÕó¿ìËÙÃİ*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
struct Mat{
	long long  f[3][3];
} ;
 long long  MOD=10000007;
Mat mul(Mat a,Mat b){
	Mat c;
	int i,j,k;
	memset(c.f,0,sizeof(c.f));
	for(i=0;i<3;i++)
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				if(a.f[i][k]==0)continue;
				if(b.f[k][j]==0)continue;
				c.f[i][j]=(c.f[i][j]+a.f[i][k]*b.f[k][j])%MOD;
			}
		}
	return c;
}
Mat pow_k(Mat a,long long k){
	Mat s;
	int i;
	memset(s.f,0,sizeof(s.f));
	for(i=0;i<3;i++)
		s.f[i][i]=1;
	while(k){
		if(k&1)
			s=mul(s,a);
		a=mul(a,a);
		k>>=1;
	}
	return s;
}
int main(){
	int n,i,j,temp;
	long long k,ans,sum;
	int a_i[100010];
	while(cin>>n&&cin>>k){
		sum=0;
		for(i=0;i<n;i++){
			cin>>a_i[i];
			sum+=a_i[i];
			sum%=MOD;
		}
		sort(a_i,a_i+n);
		Mat base;
		base.f[0][0]=1;base.f[0][1]=1;base.f[0][2]=1;
		base.f[1][0]=0;base.f[1][1]=1;base.f[1][2]=1;
		base.f[2][0]=0;base.f[2][1]=1;base.f[2][2]=0;
		base=pow_k(base,k);
		ans=(base.f[0][0]*sum+base.f[0][1]*a_i[n-1]+base.f[0][2]*a_i[n-2])%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
