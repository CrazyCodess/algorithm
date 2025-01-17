/**
* @Date 2019/2/14 16:40
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> vis;
    void backtracking(vector<vector<int>>& res, vector<int> tmp, vector<int>& nums){
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
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
        vector<vector<int>> res;
        res.clear();
        vector<bool> tmp(nums.size(), false);

        vis = tmp;
        vector<int> tmp1;
        backtracking(res, tmp1, nums);
        return res;
    }
};


