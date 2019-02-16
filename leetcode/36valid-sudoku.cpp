/**
* @Date 2019/2/15 11:27
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<char,int> nums;
    int m,n;
    void initMap(){
        nums.clear();
        for(int i=1;i<=9;i++)nums[i+'0'] = 0;
    }
    bool checkRow(vector<vector<char>>& board){
        for(int i=0;i<m;i++){
            initMap();
            for(int j=0;j<n;j++){

                char c = board[i][j];
                if(c == '.')continue;
                if(nums[c] >= 1)return false;
                nums[c]++;
            }
        }
    }

    bool checkCol(vector<vector<char>>& board,int col){
        for(int i=0;i<n;i++){
            initMap();
            for(int j=0;j<m;j++){

                char c = board[j][i];
                if(c == '.')continue;
                if(nums[c] >= 1)return false;
                nums[c]++;
            }
        }
    }

    bool checkblock(vector<vector<char>>& board){
        for(int i=0;i<m;i = i + 3){
            for(int j=0;j<n;j = j + 3){

                initMap();
                for(int l=i;l<i+3;l++){
                    for(int k=j;k<j+3;k++){
                        char c = board[l][k];
                        if(c == '.')continue;
                        if(nums[c] >= 1)return false;
                        nums[c]++;
                    }
                }
            }
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        return checkblock(board)&&checkRow(board)&&checkCol(board);
    }
};


