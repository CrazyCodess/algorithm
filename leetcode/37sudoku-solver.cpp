/**
* @Date 2019/2/16 17:17
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m,n;
    bool findBlank(vector<vector<char>>& board, int& row, int& col){
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j] == '.'){
                    row = i;
                    col = j;
                    return true;
                }
        return false;
    }
    bool usedInCol(vector<vector<char>>& board, int col, int num){
        for(int i=0;i<m;i++)if(board[i][col] == (num+'0'))return true;
        return false;
    }
    bool usedInRow(vector<vector<char>>& board, int row, int num){
        for(int i=0;i<n;i++)if(board[row][i] == (num+'0'))return true;
        return false;
    }
    bool usedInBox(vector<vector<char>>& board, int rowStart, int colStart, int num){
        for(int row=0;row<3;row++)
            for(int col=0;col<3;col++)if(board[rowStart+row][colStart+col] == (num+'0'))return true;
        return false;
    }
    bool isSafe(vector<vector<char>>& board, int row, int col, int num){
        return !usedInCol(board, col, num)&&!usedInRow(board, row, num)&&!usedInBox(board, row - row%3, col - col%3, num);
    }

    bool backtracking(vector<vector<char>>& board){
        int row = -1,col = -1;
        if(!findBlank(board, row, col))return true;
        for(int i=1;i<=9;i++){
            if(isSafe(board, row, col, i)){
                board[row][col] = i+'0';
                if(backtracking(board))return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        m = board.size();
        n = board.size();
        backtracking(board);
    }
};


