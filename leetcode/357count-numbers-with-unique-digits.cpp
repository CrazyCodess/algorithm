/**
* @Date 2019/2/17 11:01
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(int& cnt, vector<bool>& f, int n, int idx, bool start){
        if(idx == n){
            cnt++;
            return;
        }
        for(int i = 0;i<=9;i++){
            if(i==0&&start){
                backtracking(cnt, f, n, idx+1, true);
            }
            else if(!f[i]){
                f[i] = true;
                backtracking(cnt, f, n, idx+1, false);
                f[i] = false;
            }
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int> digits(n, 0);
        vector<bool> f(n, false);
        int cnt = 0;
        if(n>0){
            backtracking(cnt, f, n, 0, true);
        }
        return cnt;
    }
};


