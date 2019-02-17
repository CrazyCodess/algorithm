/**
* @Date 2019/2/17 16:25
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> words;
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
        return f[s.size()];

    }
};


