/**
* @Date 2019/2/17 12:00
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(vector<string>& res, vector<string> tmp, string s, int num, int idx){
        if(num == 4){
            if(idx<s.size())return;
            res.push_back(tmp[0]+"."+tmp[1]+"."+tmp[2]+"."+tmp[3]);
            return;
        }
        for(int i=idx;i<idx+3&&i<s.size();i++){
            int cnt = 0;
            if(i>idx&&s[idx]=='0')return;
            for(int j=idx;j<=i;j++)cnt = cnt*10 + (s[j] - '0');
            if(cnt > 255)return;
            tmp.push_back(to_string(cnt));
            backtracking(res, tmp, s, num+1, i+1);
            tmp.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()==0)return res;
        vector<string> tmp;
        backtracking(res, tmp, s, 0, 0);
        return res;
    }
};


