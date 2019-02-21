/**
* @Date 2019/2/18 21:43
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n==0)return res;
        res.resize(n);
        if(n==1){
            vector<int> tmp(n,0);
            cout<<"1";
            res[0] = tmp;
            res[0][0] = 1;
            return res;
        }
        int m = n;
        vector<vector<bool>> f;
        f.resize(n);
        for(int i=0;i<f.size();i++){
            vector<bool> tmp(n, false);
            f[i] = tmp;
            vector<int> tmp1(n,0);
            res[i] = tmp1;
        }
        int row = 0, col = 0;
        bool colr = true, rowu = false, coll = false, rowd = false;
        int cnt = 1;
        while(true){
            if(!f[row][col]){
                res[row][col] = cnt;
                f[row][col] = true;
            }
            if(colr){
                if(col < n-1 && !f[row][col+1]){
                    col++;
                    cnt++;
                    continue;
                }else{
                    rowd = true;
                    colr = false;
                }
            }
            if(rowd){
                if(row < m-1&&!f[row+1][col]){
                    row++;
                    cnt++;
                    continue;
                }else{
                    coll = true;
                    rowd = false;
                }
            }
            if(coll){
                if(col > 0&&!f[row][col-1]){
                    col --;
                    cnt++;
                    continue;
                }else{
                    rowu = true;
                    coll = false;
                }
            }
            if(rowu){
                if(row>0&&!f[row-1][col]){
                    row--;
                    cnt++;
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

