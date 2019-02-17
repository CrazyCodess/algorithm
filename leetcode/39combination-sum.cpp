/**
* @Date 2019/2/16 19:26
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrays;
    vector<int> tmp;
    vector<vector<int> > res;
    void backtracking(int target, int idx){
        if(target == 0){
            res.push_back(tmp);
            return;
        }
        if(idx>=arrays.size())return;
        int cnt = target/arrays[idx];
        for(int i=0;i<=cnt;i++){
            int t = i;
            while(t--){
                tmp.push_back(arrays[idx]);
            }
            backtracking(target - i*arrays[idx], idx+1);
            t = i;
            while(t--){
                tmp.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        res.clear();
        res.clear();
        arrays = candidates;
        tmp.clear();
        backtracking(target, 0);
        return res;
    }
};

