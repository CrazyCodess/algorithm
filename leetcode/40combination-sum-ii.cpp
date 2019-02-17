/**
* @Date 2019/2/16 20:46
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(set<vector<int>>& res, vector<int>& candidates, vector<int> tmp, int target, int idx){
        if(target == 0){
            res.insert(tmp);
            return;
        }
        if(idx>=candidates.size()||target<0)return;
        for(int i = idx; i < candidates.size(); i++){
            tmp.push_back(candidates[i]);
            backtracking(res, candidates, tmp, target - candidates[i], i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0){
            vector<vector<int>> res;
            return res;
        }
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        tmp.clear();
        set<vector<int>> ans;
        backtracking(ans, candidates, tmp, target, 0);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};


