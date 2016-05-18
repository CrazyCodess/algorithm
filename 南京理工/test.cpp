#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int T,cas;
ll a,b,n;
vector<ll> adj;

ll solve(ll x,ll n)
{
    adj.clear();
    ll i,j;
    for (i=2;i*i<=n;i++)     
        if (n%i==0)
        {
            adj.push_back(i);
            while (n%i==0)
                n/=i;
        }
    if (n>1)
        adj.push_back(n);
 
    ll sum=0,value,cnt;
    for (i=1;i<(1<<adj.size());i++)  
    {
        value=1;
        cnt=0;
        for (j=0;j<adj.size();j++)
            if (i&(1<<j))      
            {
                value*=adj[j];
                cnt++;
            }
        if (cnt&1)      
        	sum+=x/value;
        else
        	sum-=x/value;
    }
    return x-sum;
}
int main()
{
   	//cas=0;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
        printf("%lld\n",solve(b,n)-solve(a-1,n));
    }
    return 0;
}
