/**
* @Date 2019/03/15 20:34
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi  first
#define se second
typedef pair<long, long> pii;
const int maxn = 100010;
pii s[maxn];
pii fre[maxn];
long res[maxn];
bool cmp(pii p1, pii p2){
    return p1.fi<p2.fi;
}
int main(){
    int n, m;
    scanf("%d%d", &n,&m);
    long d,p;
    for(int i = 0;i<n;i++){
        scanf("%ld%ld", &d,&p);
        s[i] = mp(d, p);
    }
    for(int i =0;i<m;i++){
        scanf("%ld", &d);
        fre[i] = mp(d, i);
    }
    sort(s, s+n);
    sort(fre, fre+m, cmp);
    long maxPrice = -1;
    // for(int i=0;i<n;i++){
    //     s[i].se = max(maxPrice, s[i].se);
    //     maxPrice = max(maxPrice, s[i].se);
    // }
    int id = 0;
    long tmp = 0;
    for(int i=0;i<m;i++){
        while(id<n&&fre[i].fi>=s[id].fi){
            tmp = max(tmp, s[id].se);
            id++;
        }
        res[fre[i].se] = tmp;
    }
    for(int i=0;i<m;i++)printf("%ld\n", res[i]);
    return 0;
}