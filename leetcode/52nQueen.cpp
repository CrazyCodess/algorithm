//
// Created by dell on 2019/1/19.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cnt;
    vector<bool> col, dia1,dia2;
    void putQueen(int n,int index){
        if(index == n)cnt++;
        for(int i=0;i<n;i++){
            if(!col[i]&&!dia1[i+index]&&!dia2[i - index+n-1]){
                col[i] = true;
                dia1[i+index] = true;
                dia2[i - index+n-1] = true;
                putQueen(n, index+1);
                col[i] = false;
                dia1[i+index] = false;
                dia2[i-index+n-1] = false;
            }
        }
    }
    int totalNQueens(int n) {
        cnt = 0;
        col.clear();
        dia1.clear();
        dia2.clear();
        for(int i=0;i<n;i++){
            col.push_back(false);
        }
        for(int i=0;i<2*n - 1;i++){
            dia1.push_back(false);
            dia2.push_back(false);
        }
        putQueen(n, 0);
        return cnt;
    }
};


