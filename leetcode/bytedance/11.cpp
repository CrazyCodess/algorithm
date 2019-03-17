#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
const int maxn = 100010;
const double eps = 0.00001;
#define ll long long
double a[maxn];
double sum[maxn];
using namespace std;
int cmp(int a, int b) {
    return a > b;
}
int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        sort(a, a+n, cmp);
        sum[0] = a[0];
        for(int i = 1; i < n; i++) {
            sum[i] = sum[i-1] + a[i];
        }
        int k = n-1;
        for(; k >= 0; k--) {
            if (((sum[k]-a[k])/(double)m - a[k]) < eps) break;
        }
        double l = (sum[k]-a[k]) / (double)m;
        l = floor(100*l)/100;
        double h;
        if (k == n-1) {
            h = sum[k] / (double)m;
        } else {
            h = (sum[k] - a[k+1]) / (double) m;
        }
        //cout << l << " " << h << endl;
        double mm;

        while((h-l)>eps) {
            mm = (l+h)/2.0;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt+= int(floor(a[i]/mm));
            }
            if(cnt < m) h = mm;
            else l = mm;
          //  cout << mm << " " << cnt << " " << m << endl;
        }
        printf("%.2lf\n", mm);
    }
}
