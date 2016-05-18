#include <iostream>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <map>
#include <cmath>
using namespace std;
int a[1001];
int b[1001];
int c[1001];

int main(){
    
    //freopen("data.txt","r",stdin);
    int n;
    cin>>n;
    while(n--){
        int m,k;
        cin>>m>>k;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b)); 
        memset(c,0,sizeof(c)); 

        
        int count=0;
        while(m!=0){
            a[count++]=m%2;
            m/=2;
        }
        
        int j=0;
        while(k!=0){
            b[j++] = k%2;
            k/=2;
        }
        
        int num=0;
        int p=0;
        while(p<j){
            if(a[num]==1){
                a[num]=0;
                num++;
                continue;
            }
            else{
                a[num]=b[p];
                num++;
                p++;
            }
        }
        
        long long sum=0;
        for(int i=0;i<num;i++){
            if(a[i]==1){
                sum+=pow(2,i);
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
