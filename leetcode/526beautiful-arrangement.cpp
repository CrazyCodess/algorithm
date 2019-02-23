/**
* @Date 2019/2/23 16:56
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(int &n, int &cnt, int idx, vector<bool> &f){
        if(idx == n+1)cnt++;
        for(int i=1;i<=n;i++){
            if(f[i])continue;
            if(idx % i == 0||i % idx == 0){
                f[i] = true;
                backtracking(n, cnt, idx+1);
                f[i] = false;
            }
        }
    }
    int countArrangement(int N) {
        vector<bool> f(N+1, false);
        int cnt = 0;
        backtracking(N, cnt, 1, f);
        return cnt;
    }
};


