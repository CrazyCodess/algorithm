#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
LL scan() {      
    LL res = 0, flag = 0;  
    char ch;  
    if((ch = getchar()) == '-') flag = 1;  
    else if(ch >= '0' && ch <= '9') res = ch - '0';  
    while((ch = getchar()) >= '0' && ch <= '9')  
        res = res * 10 + (ch - '0');  
    return flag ? -res : res;  
}  
void out(LL a) {     
    if(a < 0) { putchar('-'); a = -a; }  
    if(a >= 10) out(a / 10);  
    putchar(a % 10 + '0');  
}  
LL findk(LL n){
    LL cnt = 0;
    while(n){
        if(n & 1)
            cnt++;
        n >>= 1;
    }
    return cnt;
}
LL findLast(LL n){
    LL cnt = 0;
    while(n){
        if(n & 1){
            break;
        }
        cnt++;
        n >>= 1;
    }
    return cnt;
}
LL subk(LL n){
    LL m = n;
    bool istart = false;
    LL tmp = 1;
    while(n){
        if(n & 1){
            m -= tmp;
            tmp <<= 1;
            istart = true;
        }else{
            if(istart){
                istart = false;
                m += tmp;
                tmp <<= 1;
                break;
            }else{
                tmp <<= 1;
            }
        }
        n >>= 1;
    }
    if(istart){
        return tmp;
    }
    return m;
}
LL addk(LL n,LL k){
    LL m = n;
    LL cnt = 0;
    while(k--){
        while(n & 1){
            n >>= 1;
            cnt++;
        }
        m += (1 << cnt);
        n >>= 1;
        cnt++;
    }
    return m;
}

int main(){
    // freopen("in","r",stdin); 
    int T;
    LL n,s1,s2,k;
    int ans = 0;
    scanf("%d",&T);
    while(T--){
        n = scan();
        s1 = scan();
        s2 = scan();
        // scanf("%d%d%d",&n,&s1,&s2);
        n++;
        k = findk(n);
        if(k < s1){
            n = addk(n,s1-k);
        }else if(k > s2){
            while(k > s2){
                n = subk(n);
                k = findk(n);
            }
            if(k < s1){
                n = addk(n,s1-k);
            }
        }
        printf("Case #%d: %lld\n",++ans,n);
    }
    return 0;
}