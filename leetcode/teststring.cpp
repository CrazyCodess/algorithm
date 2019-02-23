//
// Created by dell on 2019/1/19.
//

//
// Created by dell on 2018/12/22.
//
#include<bits/stdc++.h>
#include <bitset>
#include <string> 
#include <math.h>   
#include<map>
#include<algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    int search(string word){
        TrieNode *ptr = root;
        for(int i=word.size()-1;i>=0;i--){
            if(!ptr->child[word[i] - 'a'])return -1;
            

            ptr = ptr->child[word[i] - 'a'];
            cout<<word[i]<<" "<<ptr->idx<<"\n";
        }
        if(ptr->is_end)return ptr->idx;
        return -1;
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
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<int> tmp(2, -1);
        vector<vector<int> > res;
        for(int i=0;i<words.size();i++)insert(words[i], i);
        for(int i=0;i<words.size();i++){
          cout<<words[i]<<"\n";
            int idx = search(words[i]);
            if(idx != -1&&idx != i){
                tmp[1] = i;
                tmp[0] = idx;
                res.push_back(tmp);
            }
        }
        return res;
    }
};
int main(){
  //Solution solu;
  // vector<int> cand;
  // cand.push_back(2);
  // cand.push_back(3);
  // cand.push_back(6);
  // cand.push_back(7);
  // solu.combinationSum(cand, 7);
    //solu.palindromePairs(words);
  char s = 'A';
  s = toupper(s);
    cout<<s;


  return 0;
}
