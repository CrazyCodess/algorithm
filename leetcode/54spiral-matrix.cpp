/**
* @Date 2019/2/18 20:38
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0)return res;
        if(matrix.size()==1)return matrix[0];
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> f;
        f.resize(matrix.size());
        for(int i=0;i<f.size();i++){
            vector<bool> tmp(matrix[0].size(), false);
            f[i] = tmp;
        }
        int row = 0, col = 0;
        bool colr = true, rowu = false, coll = false, rowd = false;

        while(true){
            if(!f[row][col]){
                res.push_back(matrix[row][col]);
                f[row][col] = true;
            }
            if(colr){
                if(col < n-1 && !f[row][col+1]){
                    col++;
                    continue;
                }else{
                    rowd = true;
                    colr = false;
                }
            }
            if(rowd){
                if(row < m-1&&!f[row+1][col]){
                    row++;
                    continue;
                }else{
                    coll = true;
                    rowd = false;
                }
            }
            if(coll){
                if(col > 0&&!f[row][col-1]){
                    col --;
                    continue;
                }else{
                    rowu = true;
                    coll = false;
                }
            }
            if(rowu){
                if(row>0&&!f[row-1][col]){
                    row--;
                    continue;
                }else{
                    colr = true;
                    rowu = false;
                }
            }
            if(col==0&&f[row][col+1]&&f[row-1][col])break;
            if(row>0&&col>0&&row<m-1&&col<n-1){
                if(f[row-1][col]&&f[row+1][col]&&f[row][col+1]&&f[row][col-1])break;
            }
        }
        return res;
    }
};


