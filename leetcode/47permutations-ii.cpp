/**
* @Date 2019/2/16 21:04
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> vis;
    void backtracking(set<vector<int>>& res, vector<int> tmp, vector<int>& nums){
        if(tmp.size() == nums.size()){
            res.insert(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i] = true;
                tmp.push_back(nums[i]);
                backtracking(res, tmp, nums);
                tmp.pop_back();
                vis[i] = false;
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        res.clear();
        vector<bool> tmp(nums.size(), false);

        vis = tmp;
        vector<int> tmp1;
        backtracking(res, tmp1, nums);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};


