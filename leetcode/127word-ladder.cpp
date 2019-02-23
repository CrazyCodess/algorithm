/**
* @Date 2019/2/22 11:24
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool cmp(string src, string dist){
        int count = 0;
        for(int i=0;i<src.size();i++){
            if(src[i] != dist[i])count++;
            if(count >=2 )return false;
        }
        return count == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> flag(wordList.size(), false);
        int cnt = INT_MAX;
        queue<pair<string, int>> que;
        que.push({beginWord, 1});
        while(!que.empty()){
            pair<string, int> tmp = que.front();
            if(tmp.first == endWord && tmp.second < cnt){
                cnt = tmp.second;
            }
            que.pop();
            for(int i=0;i<wordList.size();i++){
                if(flag[i])continue;
                if(!cmp(tmp.first, wordList[i]))continue;
                que.push({wordList[i], tmp.second+1});
                flag[i] = true;
            }
        }
        if(cnt == INT_MAX)return 0;
        return cnt;
    }
};

