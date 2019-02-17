/**
* @Date 2019/2/17 15:57
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(vector<string>& res, string& s,set<string>& words, vector<string>& tmp, int idx){
        if(idx == s.size()){
            string str;
            for(int i=0;i<tmp.size()-1;i++)str+=tmp[i] + " ";
            str += tmp[tmp.size()-1];
            res.push_back(str);
            return;
        }
        for(int i=idx;i<s.size();i++){
            string str(s.begin()+idx, s.begin()+i+1);
            if(words.find(str) != words.end()){
                tmp.push_back(str);
                backtracking(res, s, words, tmp, i+1);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if(s.size()==0||wordDict.size()==0)return res;
        set<string> words;
        vector<string> tmp;
        for(int i=0;i<wordDict.size();i++)words.insert(wordDict[i]);

        vector<bool> f(s.size()+1, false);
        f[0] = true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                string str(s.begin()+j, s.begin()+i);
                if(f[j]&&words.find(str) != words.end()){
                    f[i] = true;
                    break;
                }
            }
        }
        if(f[s.size()])
        backtracking(res, s, words, tmp, 0);
        return res;
    }
};


