/**
* @Date 2019/2/23 10:47
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<int>> &res, int &k, int n, vector<int> &tmp, int idx){
        for(int i=idx;i<=9;i++){
            if(n - i <0)return;
            if(n - i == 0){
                if(tmp.size() == k-1){
                    tmp.push_back(i);
                    res.push_back(tmp);
                    tmp.pop_back();
                }
                return;
            }
            tmp.push_back(i);
            backtracking(res, k, n-i, tmp, i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtracking(res, k, n, tmp, 1);
        return res;
    }
};


