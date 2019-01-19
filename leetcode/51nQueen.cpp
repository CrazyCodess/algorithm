//
// Created by dell on 2019/1/18.
//

//
// Created by dell on 2018/12/22.
//
#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> res;
vector<bool> col, dia1,dia2;
vector<string> generate(int n, vector<int> &row){
    vector<string> board(n,string(n,'.'));
    for(int i=0;i<n;i++){
        board[i][row[i]] = 'Q';
    }
    return board;
}

void putQueen(int n, int index, vector<int> &row){
    if(index == n){
        res.push_back(generate(n, row));
        return;
    }
    for(int i=0;i<n;i++){
        if(!col[i]&&!dia1[index+i]&&!dia2[i - index + n-1]){
            row.push_back(i);
            col[i] = true;
            dia1[index+i] = true;
            dia2[i - index+ n-1] = true;
            putQueen(n, index+1, row);
            row.pop_back();
            col[i] = false;
            dia1[index+i] = false;
            dia2[i - index+n-1] = false;
        }
    }
    return;
}



vector<vector<string>> solveNQueens (int n)
{
    res.clear();
    dia1.clear();
    dia2.clear();
    for(int i =0;i<n;i++){
        col.push_back(false);
    }
    for(int i =0;i<2*n - 1;i++){
        dia1.push_back(false);
        dia2.push_back(false);
    }
    vector<int> row;
    putQueen(n, 0, row)

    return res;
}


