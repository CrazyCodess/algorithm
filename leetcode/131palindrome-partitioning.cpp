/**
* @Date 2019/2/17 15:37
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s){
        if(s.size() == 0)return false;
        if(s.size() == 1)return true;
        int l = 0, r= s.size()-1;
        while(l<r){
            if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void backtracking(vector<vector<string>>& res, vector<string>& tmp, string& s, int idx){
        if(idx == s.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            string str(s.begin()+idx, s.begin()+i+1);
            if(isPalindrome(str)){
                tmp.push_back(str);
                backtracking(res, tmp, s, i+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        if(s.szie()<=0)return res;
        backtracking(res, tmp, s, 0);
        return res;
    }
};


