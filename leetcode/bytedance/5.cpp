/**
* @Date 2019/03/10 20:07
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
const int maxn = 1000010;
typedef pair<long,int> pii;
pii s[maxn];
bool cmp(pii p1, pii p2){
    
}
int main(){
    int n;
    vector<long> A;
    scanf("%d", &n);
    long a, v = LONG_MAX;
    for(int i=0;i<n;i++){
        scanf("%ld", &a);
        A.push_back(a);
        if(a<v) v = a;
    }
    for(int i=0;i<n;i++){
        s[i] = mp(abs(A[i] - a), i);
    }

    for(int i=1;i<n;i++){

        for(int j=0;j<i;j++){
            
            if(s[i].fi>abs(A[i] - A[j])){
                s[i] = mp(abs(A[i] - A[j]), j);
            }else if(s[i].fi == abs(A[i] - A[j])&&(s[i].se == -1 || A[s[i].se]>A[j])){
                s[i] = mp(abs(A[i] - A[j]), j);
            }
        }
    }
    for(int i=1;i<n;i++){
        printf("%ld %d\n", s[i].fi, s[i].se+1);
    }

    return 0;
}