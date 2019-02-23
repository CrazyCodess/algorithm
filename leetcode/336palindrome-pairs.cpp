/**
* @Date 2019/2/21 15:11
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
#define TRIE_MAX_CHAR_NUM 26
struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    int idx;
    TrieNode():is_end(false), idx(-1){
        for(int i=0;i<TRIE_MAX_CHAR_NUM;i++)child[i] = NULL;
    }
};
class Solution {
public:
    TrieNode *root = new TrieNode();
    void search(string& word, vector<int>& list){
        TrieNode *ptr = root;
        for(int i=word.size()-1;i>=0;i--){
            if(!ptr->child[word[i] - 'a'])return;
            ptr = ptr->child[word[i] - 'a'];
            if(ptr->is_end&&isPalindrome(word, i-1))list.push_back(ptr->idx);
        }
    }
    void insert(string word, int idx){
        TrieNode *ptr = root;
        int pos;
        for(int i=0;i<word.size();i++){
            pos =word[i] - 'a';
            if(!ptr->child[pos])ptr->child[pos] = new TrieNode();
            ptr = ptr->child[pos];
        }
        ptr->is_end = true;
        ptr->idx = idx;
    }
    bool isPalindrome(string& word, int end){
        int l=0, r = end;
        while(l<r){
            if(word[l] != word[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<int> tmp(2, -1);
        vector<int> list;
        vector<vector<int>> res;
        for(int i=0;i<words.size();i++)insert(words[i], i);
        for(int i=0;i<words.size();i++){
            if(words[i].size() == 0){
                for(int j=0;j<words.size();j++){
                    if(i != j&&isPalindrome(words[j], words[j].size()-1)){
                        tmp[1] = i;
                        tmp[0] = j;
                        res.push_back(tmp);
                        tmp[1] = j;
                        tmp[0] = i;
                        res.push_back(tmp);
                    }
                }
                continue;
            }
            list.clear();
            search(words[i], list);
            for(int j=0;j<list.size();j++){
                if(list[j] != i){
                    tmp[1] = i;
                    tmp[0] = list[j];
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};


