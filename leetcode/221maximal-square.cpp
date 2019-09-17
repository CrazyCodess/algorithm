#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)return 0;
        int m = matrix[0].size();
        if(m == 0)return 0;
        int dp[n][m];

        for(int i = 0;i < n;i++)dp[i][0] = int(matrix[i][0] - '0');
        for(int i = 0;i < n;i++){
            for(int j = 1;j < m;j++){
                if(matrix[i][j] == '1')dp[i][j] = dp[i][j-1]+1;
                else dp[i][j] = 0;
            }
        }

        int ans = 0;
        int max_width;
        bool f;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                max_width = dp[i][j];
                //cout<<i<<" "<<j<<" "<<max_width<<endl;
                max_width = min(n - i, max_width);
                f = true;
                for(int k = i;k < n && k < i + max_width;k++){
                    // if(dp[k][j] < max_width){
                    //     f = false;
                    //     break;
                    // }
                    max_width = min(max_width, dp[k][j]);
                }
                
                //if(f)ans = 
                ans = max(ans, max_width * max_width);
            }
        }
        return ans;

    }
};
int main(){
    vector<vector<char>> matrix = {{'1','0','1','1','1','0','0','0','1','0'},{'0','1','0','0','0','0','0','1','1','0'},{'0','1','0','1','0','0','0','0','1','1'},{'1','1','1','0','0','0','0','0','1','0'},{'0','1','1','1','0','0','1','0','1','0'},{'1','1','0','1','1','0','1','1','1','0'}};
    Solution sol;
    cout<<sol.maximalSquare(matrix)<<endl;
    
    return 0;
}