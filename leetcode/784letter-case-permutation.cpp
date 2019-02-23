/**
* @Date 2019/2/23 17:11
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    void backtracking(string &S, vector<string> &res, string tmp, int idx){
        if(idx == S.size()){
            res.push_back(tmp);
            return;
        }
        if((S[idx]>='a'&&S[idx]<='z')||(S[idx]>='A'&&S[idx]<='Z')){
            tmp.push_back(tolower(S[idx]));
            backtracking(S, res, tmp, idx+1);
            tmp.pop_back();
            tmp.push_back(toupper(S[idx]));
            backtracking(S, res, tmp, idx+1);
        }else {
            tmp.push_back(S[idx]);
            backtracking(S, res, tmp, idx+1);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string tmp = "";
        backtracking(S, res, tmp, 0);
        return res;
    }
};


