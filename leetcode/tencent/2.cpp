#include<bits/stdc++.h>
using namespace std;
unsigned int arr[32];
int main(){
    int n,m;
    scanf("%d%d", &n,&m);
    if(!(n >= 1&&n <= 1024) || !(m >= 1 && m<= 1024)){
        cout<< -1<<endl;return 0;
    }
    arr[(n-1)>>5] |= (1 << (n&31));
    cout<<(( arr[(m - 1)>>5] & (1 << (m&31)) ) != 0)<<endl;
    return 0;
}