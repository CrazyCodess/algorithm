#include<bits/stdc++.h>  
using namespace std;

#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;

const int maxn = 200005;
pii s[maxn];
int n, ans, d, id, ma;

int main()
{
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; i ++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        s[i] = mp(x, y);
    }
    sort(s + 1, s + n + 1);
    for(int i = 1; i <= n; i ++)printf("%d %d\n", s[i].fi, s[i].se);
    ans = 0; id = 1; ma = 0;
    for(int i = 2; i <= n; i ++)
    {
        while(id < i && s[id].fi + d <= s[i].fi) { ma = max(ma, s[id].se); id ++;}
        ans = max(ans, s[i].se + ma);
    }
    printf("%d\n",ans);
    return 0;
}