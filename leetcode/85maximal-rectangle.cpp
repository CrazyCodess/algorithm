#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max_area = 0;
        int n = matrix.size();
        if(n == 0)return max_area;
        int m = matrix[0].size();
        if(m == 0)return max_area;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(j == 0)dp[i][j] = (int)(matrix[i][j] - '0');
                else{
                    if (matrix[i][j] != '0')
                    dp[i][j] = dp[i][j] = dp[i][j - 1] + 1;
                }
                max_area = max(max_area, dp[i][j]);
            }
        }
        int max_width;
        for(int j = 0;j < m;j++){
            for(int i = 0;i < n;i++){
                max_width = dp[i][j];
                for(int k = i-1;k >= 0;k--){
                    max_width = min(max_width, dp[k][j]);
                    max_area = max(max_area, max_width * (i - k + 1));
                }
            }
        }
        return max_area;
    }
};
int main(){
    Solution sol ;
    vector<vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};
    cout<<sol.maximalRectangle(matrix)<<endl;
    return 0;
}