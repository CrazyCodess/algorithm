#include<iostream>
using namespace std;
const int MAXN=1010;
int F[MAXN];
int find(int t)
{
    if(F[t]==-1) return t;
    return F[t]=find(F[t]);
}    
void bing(int a,int b)
{
    int t1=find(a);
    int t2=find(b);
    if(t1!=t2) F[t1]=t2;
}    
int main()
{
    int n,m;

    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(int i=1;i<=n;i++) F[i]=-1;
        int a,b;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            bing(a,b);
        }    
        int res=0;
        for(int i=1;i<=n;i++)
          if(F[i]==-1) res++;
        printf("%d\n",res-1);
    }    
    return 0;
}