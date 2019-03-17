/**
* @Date 2019/2/23 17:37
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<int>>& grid, int& cnt, int row, int col, vector<vector<bool>>& f,int step){
        if(row<0||col<0||row>=grid.size()||col>=grid[0].size())return;
        if(grid[row][col] == 2){
            if(step = grid.size()*grid[0].size() - 1)cnt++;
            return;
        }
        if(f[row][col]||grid[row][col]==-1)return;
        f[row][col] = true;
        backtracking(grid, cnt, row-1, col, f, step + 1);
        backtracking(grid, cnt, row+1, col, f, step + 1);
        backtracking(grid, cnt, row, col-1, f, step + 1);
        backtracking(grid, cnt, row, col+1, f, step + 1);
        f[row][col] = false;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cnt = 0;
        bool isFind = false;
        vector<vector<bool>> f;
        for(int i=0;i<grid.size();i++){
            vector<bool> tmp(grid[0].size(), false);
            f.push_back(tmp);
        }
        //f[0][0] = true;
        int row = -1, col = -1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    isFind = true;
                    row = i;
                    col = j;
                    break;
                }
            }
            if(isFind)break;
        }
        backtracking(grid, cnt, row, col, f, 1);
        return cnt;
    }
};


