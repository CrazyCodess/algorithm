#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100010];
int main(){
    int T, a;
    bool f;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0;i <= n;i++)arr[i] = 0;
        for(int i=0;i<n;i++){
            scanf("%d", &a);
            arr[a]++;
        }
        
        f = true;
        for(int i = 0;i <= n;i++){
            //cout<<arr[i]<<endl;
            if(arr[i] > (n/2)){
                f = false;
                break;
            }
        }
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}