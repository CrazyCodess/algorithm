#include <stdio.h>
#include <string.h>
#define mod 100000007
inline int GCD(int a,int b){
    for(int c;b;c=b,b=a%b,a=c);
    return a;
}
long long ans;
int a[1010],f[1010][1010];
int main(){
    int T,n;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;++i){
            ++f[i][a[i]];
            if(i!=n)
            for(int j=1;j<=1000;++j)if(f[i][j]){
                (f[i+1][GCD(a[i+1],j)]+=f[i][j])%=mod;
                (f[i+1][j]+=f[i][j])%=mod;
            }
        }
        ans=0;
        for(int i=1;i<=1000;++i)
            ans=(ans+(long long)i*f[n][i])%mod;
        int ANS=ans;
        printf("%d\n",ANS);
    }
}
