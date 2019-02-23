/**
* @Date 2019/2/21 12:17
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
class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root = new TrieNode();
    WordDictionary() {
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *ptr = root;
        for(int i=0;i<word.size();i++){
            if(word[i] == '.')continue;
            int pos = word[i] - 'a';
            if(!ptr->child[pos]){
                TrieNode *node = new TrieNode();
                ptr->child[pos] = node;
            }
            ptr = ptr->child[pos];
        }
        ptr->is_end = true;
    }
    bool search_trie(TrieNode *node, const char *word){
        if(*word == '\0'){
            if(node->is_end == true)return true;
            return false;
        }
        if(*word == '.'){
            for(int i=0;i<TRIE_MAX_CHAR_NUM;i++){
                if(node->child[i]&&search_trie(node->child[i], word+1))return true;
            }
        }else{
            int pos = *word - 'a';
            if(node->child[pos]&&search_trie(node->child[pos], word+1))return true;
        }
        return false;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_trie(root, word.c_str());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

