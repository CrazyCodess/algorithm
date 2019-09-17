#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[59];
    int value(int n){
        if(n <= 3)return n;
        if(dp[n] != -1)return dp[n];
        for(int i = 1;i <= n/2;i++){
            dp[i] = value(i);
            dp[n-i] = value(n - i);
            dp[n] = max(dp[n], dp[i]*dp[n-i]);
        } 
        //cout<<n<<" "<<dp[n]<<endl;
        return dp[n];
    }
    int integerBreak(int n) {
        if(n <= 2)return 1;
        dp[1] = dp[2] = 1;
        dp[3] = 2;
        for(int i = 4;i <= n;i++)dp[i] = -1;
        value(n);
        return dp[n];
    }
};

class Solution1 {
public:
    int integerBreak(int n) {
        int base = int(sqrt(n));
        int e = n/base;
        int res = int(pow(base, e));
        res = res*(n - res);
        return res;
    }
};

int main(){
    Solution sol;
    for(int i = 1;i <= 58;i++)
    cout<<i<<" "<<sol.integerBreak(i)<<endl;
    return 0;
}