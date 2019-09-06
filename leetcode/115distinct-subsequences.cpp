#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        long dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i <= n;i++)dp[i][0] = 1;
        for(int i = 1;i <= m;i++)dp[0][i] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                //cout<<i<<" "<<j<<endl;
                if(s[i-1] == t[j-1])dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return int(dp[n][m]);
    }
};