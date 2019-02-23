/**
* @Date 2019/2/21 17:09
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
#define TRIE_MAX_CHAR_NUM 26
struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode():is_end(false){
        for(int i=0;i<TRIE_MAX_CHAR_NUM;i++)child[i] = NULL;
    }
};
class Solution {
public:
    TrieNode *root = new TrieNode();
    void insert(string word){
        TrieNode *ptr = root;
        int pos;
        for(int i=0;i<word.size();i++){
            pos = word[i] - 'a';
            if(!ptr->child[pos])ptr->child[pos] = new TrieNode();
            ptr = ptr->child[pos];
        }
        ptr->is_end = true;
    }
    bool startWith(string word){
        int pos;
        TrieNode *ptr = root;
        for(int i=0;i<word.size();i++){
            pos = word[i] - 'a';
            if(!ptr->child[pos])return false;
            ptr = ptr->child[pos];
        }
        return true;
    }
    bool search(string word){
        int pos;
        TrieNode *ptr = root;
        for(int i=0;i<word.size();i++){
            pos = word[i] - 'a';
            if(!ptr->child[pos])return false;
            ptr = ptr->child[pos];
        }
        return ptr->is_end;
    }
    void backtracking(vector<vector<char>>& board, int i, int j, string str, set<string>& res){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()){
            char tmp= board[i][j];
            if(tmp == '#')return;
            str += tmp;
            if(!startWith(str))return;
            if(search(str))res.insert(str);
            board[i][j] = '#';
            backtracking(board, i-1, j, str, res);
            backtracking(board, i+1, j, str, res);
            backtracking(board, i, j-1, str, res);
            backtracking(board, i, j+1, str, res);
            board[i][j] = tmp;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i=0;i<words.size();i++)insert(words[i]);
        set<string> res;
        for(int i=0;i<board.size();i++)for(int j=0;j<board[0].size();j++)backtracking(board, i, j, "", res);
        vector<string> ans(res.begin(), res.end());

        return ans;
    }
};


