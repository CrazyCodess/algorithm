/**
* @Date 2019/2/22 9:50
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<string>>& res, string word, string endWord, vector<string>& wordList, vector<string>& tmp, vector<bool>& flag){
        for(int i=0;i<wordList.size();i++){
            if(flag[i])continue;
            int cnt = 0;
            for(int j=0;j<word.size();j++){
                if(word[j]!=wordList[i][j]){
                    if(cnt>=1)return;
                    cnt++;
                }
            }
            if(cnt != 1)continue;
            flag[i] = true;
            tmp.push_back(wordList[i]);
            if(wordList[i] == endWord){
                res.push_back(tmp);
                return;
            }
            backtracking(res, wordList[i], endWord, wordList, tmp, flag);
            flag[i] = false;
            tmp.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<string> tmp;
        tmp.push_back(beginWord);
        vector<bool> flag(wordList.size(), false);
        backtracking(res, beginWord, endWord, wordList, tmp, flag);
        return res;
    }
};


