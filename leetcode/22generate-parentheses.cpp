/**
* @Date 2019/2/16 15:39
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(string sublist, vector<string>& res, int left, int right){
        if(left==0&&right==0){
            res.push_back(sublist);
            return;
        }
        if(left>0){
            backtracking(sublist+"(", res, left-1, right);
        }
        if(left<right){
            backtracking(sublist+")", res, left, right-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking("", res, n, n);
        return res;
    }
};


