/**
* @Date 2019/2/23 16:18
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int permuCount(int n){
        if(n==0)return 1;
        int count = 1;
        for(int i=1;i<=n;i++){
            count *= i;
        }
        return count;
    }
    string getPermutation(int n, int k) {
        vector<bool> f(n+1, false);
        int cnt = 0, m = n-1,count, p;
        string res = "";
        if(k>=permuCount(n)){
            for(int i=n;i>=1;i--)res += (i+ '0');
        }else
            while(res.size() != n){
                if(k == 1){
                    for(int i=1;i<=n;i++){
                        if(f[i])continue;
                        f[i] = true;
                        res += (i+'0');
                        break;
                    }
                }else{
                    p = permuCount(m);
                    cnt = (k-1)/p;
                    count = 0;
                    for(int i=1;i<=n;i++){
                        if(f[i])continue;
                        if(count == cnt){
                            f[i] = true;
                            res += (i+'0');
                            break;
                        }
                        count++;
                    }
                    k -=  p*cnt;
                    m--;
                }
            }
        return res;
    }
};


