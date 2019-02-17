/**
* @Date 2019/2/16 22:01
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m;
    void backtracking(vector<vector<int>>& res, vector<int> tmp, int idx, int k){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        for(int i = idx;i<=m-k+1;i++){
            tmp.push_back(i);
            backtracking(res, tmp, i+1, k);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        m = n;
        vector<vector<int>> res;
        if(n==0)return res;
        vector<int> tmp;
        backtracking(res, tmp, 1, k);
        return res;
    }
};


