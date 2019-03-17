/**
* @Date 2019/03/16 22:15
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
#define  mp make_pair
#define  fi first
#define  se second

//拓扑排序解法
// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> in(n, vector<int>(m,0));
//         vector<vector<vector<pair<int, int>>>> edges(n, vector<vector<pair<int, int>>>(m,vector<pair<int, int>>()));
//         int d[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
//         int cnt, row, col;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 cnt = matrix[i][j];
//                 for(int k=0;k<4;k++){
//                     row = d[k][0] + i;
//                     col = d[k][1] + j;
//                     if(row>=0 && row<n && col>=0 && col<m){
//                         if(matrix[row][col]>cnt){
//                             in[row][col]++;
//                             edges[i][j].push_back(mp(row, col));
//                         }
//                     }
//                 }
//             }
//         }
//     }
// };

//dfs解法
class Solution1{
    public:
    int result = 0;
    int n;
    int m;
    int d[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &maxPath, int i, int j, int steps){
        if(maxPath[i][j])return maxPath[i][j];
        int tmpPath = 1;
        int row, col;
        int cnt = matrix[i][j];
        for(int k=0;k<4;k++){
            row = d[k][0] + i;
            col = d[k][1] + j;
            if(row>=0 && row<n && col>=0 && col<m && matrix[row][col] >cnt){
                maxPath[row][col] = dfs(matrix, maxPath, row, col, steps+1);
                tmpPath = max(tmpPath, maxPath[row][col] + 1);
            }
        }
        return tmpPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix){
        n = matrix.size();
        if(n==0)return 0;
        m = matrix[0].size();
        if(m==0)return 0;
        result = 0;
        vector<vector<int>> maxPath(n, vector<int>(m,0));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            maxPath[i][j] = dfs(matrix, maxPath,i, j, 1);
            result = max(result, maxPath[i][j]);
        }
        return result;
    }
};