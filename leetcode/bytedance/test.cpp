#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> pii;
pii s[10];
int main(){
    long n, a, x;
    vector<long> xs;
    scanf("%ld%ld", &n, &x);
    for(int i=0;i<n;i++){
        scanf("%ld", &a);
        xs.push_back(a);
    }
    sort(xs.begin(), xs.end());
    long res  = LONG_MAX;
    res = min(abs(x - xs[1])+abs(xs[n-1]- xs[1]), abs(x - xs[n-1])+abs(xs[n-1]- xs[1]));
    res = min(res, abs(x - xs[0])+abs(xs[n-2]- xs[0]));
    res = min(res, abs(x - xs[n-2])+abs(xs[n-2]- xs[0]));
    printf("%ld\n", res);
    return 0;

}