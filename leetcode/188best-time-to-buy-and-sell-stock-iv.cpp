#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int profit(vector<int>& prices){
        int n = prices.size();
        int dp[n+1][2];
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for(int i = 1;i <= n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]);
        }
        return dp[n][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= n/2)return profit(prices);
        else{
            int dp[n+1][k+1][2];
            
            for(int i = 0;i <= n;i++){
                dp[i][0][0] = 0;
                dp[i][0][1] = INT_MIN;
                for(int j = k;j >= 1;j--){
                    if(i == 0){
                        dp[i][j][0] = 0;
                        dp[i][j][1] = INT_MIN;
                    }else{
                        dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i-1]);
                        dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i - 1]);
                    }
                }
            }
            return dp[n][k][0];
        }
    }
};