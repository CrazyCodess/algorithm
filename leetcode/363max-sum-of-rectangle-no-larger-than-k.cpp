#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n <= 0)return 0;
        int m = matrix[0].size();
        if(m <=0 )return 0;
        int dp[n][m+1];
        int ans = INT_MIN;
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= m;j++){
                if(j == 0)dp[i][j] = 0;
                //else if(j == 1)dp[i][j] = matrix[i][j-1];
                else{
                    dp[i][j] = dp[i][j - 1] + matrix[i][j-1];
                }
                if(dp[i][j] <= k && j > 0)ans = max(dp[i][j], ans);
                //if(j>0 && matrix[i][j-1] <= k)ans = max(matrix[i][j-1], ans);
                if(ans == k)return ans;
            }
        }
        int tmp;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                for(int l = j+1;l <= m;l++){
                    tmp = dp[i][l] - dp[i][j];
                    if(tmp <= k)ans = max(ans, tmp);
                    for(int y = i+1;y < n;y++){
                        tmp += dp[y][l] - dp[y][j];
                        if(tmp <= k)ans = max(ans, tmp);
                    }
                    if(ans == k)return ans;
                }

            }
        }
        return ans;
    }
};