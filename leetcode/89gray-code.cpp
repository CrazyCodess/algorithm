/**
* @Date 2019/2/17 10:29
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int toInt(vector<int> codes){
        int res = 0;
        for(int i=0;i<codes.size();i++){
            res += codes[i]*int(pow(2, i));
        }
        return res;
    }
    void backtracking(vector<int>& res, vector<int> codes, vector<bool> f, int num){
        for(int i=0;i<codes.size();i++){
            codes[i] = 1 - codes[i];
            int s = toInt(codes);
            if(!f[s]) {
                res.push_back(s);
                f[s] = true;
                if (res.size() < num)backtracking(res, codes, f, num);
            }else{
                codes[i] = 1 - codes[i];
            }
        }
    }
    vector<int> grayCode(int n) {
        int num = int(pow(2, n));
        vector<bool> f(num, false);
        vector<int> codes(n, 0);
        vector<int> res;
        if(n>0){
            res.push_back(0);
            f[0] = true;
            backtracking(res, codes, f, num);
        }
        return res;
    }
};


