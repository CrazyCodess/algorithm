/**
* @Date 2019/2/21 11:41
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
#define TRIE_MAX_CHAR_NUM 26
struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode():is_end(false){
        for(int i=0;i<TRIE_MAX_CHAR_NUM;i++)child[i] = 0;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode root;
    Trie() {}
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *ptr = &root;
        for(int i=0;i<word.size();i++){
            int pos = word[i] - 'a';
            if(!ptr->child[pos]){
                TrieNode *node = new TrieNode();
                ptr->child[pos] = node;
            }
            ptr = ptr->child[pos];
        }
        ptr->is_end = true;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ptr = &root;
        for(int i=0;i<word.size();i++){
            if(!ptr->child[word[i] - 'a'])return false;
            ptr = ptr->child[word[i] - 'a'];
        }
        return ptr->is_end;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *ptr = &root;
        for(int i=0;i<prefix.size();i++){
            if(!ptr->child[prefix[i] - 'a'])return false;
            ptr = ptr->child[prefix[i] - 'a'];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */


