/**
* @Date 2019/2/21 17:41
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<char>>& board, int i, int j, bool& flag, const char *w){

        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()){
            if(board[i][j] != *w)return;
            char tmp= board[i][j];
            if(tmp == '#')return;
            board[i][j] = '#';
            if(tmp == *w){
                backtracking(board, i-1, j, flag, w+1);
                backtracking(board, i+1, j, flag, w+1);
                backtracking(board, i, j-1, flag, w+1);
                backtracking(board, i, j+1, flag, w+1);
            }
            board[i][j] = tmp;
        }
        if(*w == '\0'){
            flag = true;
            return;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool flag = false;
        for(int i=0;i<board.size();i++)for(int j=0;j<board[0].size();j++)backtracking(board, i, j, flag, word.c_str());
        return flag;
    }
};


