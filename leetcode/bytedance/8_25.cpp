#include<bits/stdc++.h>
using namespace std;
bool gcd(int x, int y){
    if (x <= 1||y <= 1)return false;
    int z = y;
    while(x%y != 0){
        z = x%y;
        x = y;
        y = z;
    }
    return z > 1;
}
int d[20020];
int num[20020];
int main(){
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &num[i]);
        d[i] = 1;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(gcd(num[i], num[j]) && (d[j] + 1) > d[i]){
                d[i] = d[j] + 1;
            }
        }
    }

    int ma = 1;
    for(int i = 0;i<n;i++){
        cout<<d[i]<<" ";
        if(d[i] > ma)ma = d[i];
    }
    printf("%d\n", ma);
    return 0;
 }