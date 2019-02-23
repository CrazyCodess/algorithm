/**
* @Date 2019/2/23 12:22
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long toInt(string &num, int i, int j){
        long long count = 0;
        if(j>i&&num[i] == '0')return -1;
        for(int k = i; k<=j;k++){
            count = count*10 + (num[k] - '0');
            if(count>INT_MAX)return -1;
        }
        return count;
    }
    void backtracking(string &num, long long first, long long second, vector<int> &res, int idx, int w, bool &flag){
        if(flag)return;
        if(idx>=num.size()){
            flag = true;
            return;
        }
        for(int i = idx;i<num.size();i++){
            if(i - idx +1 > w + 1)return;
            long long count = toInt(num, idx, i);
            if(count == -1)return;
            if(count != first + second)continue;
            res.push_back(count);
            backtracking(num, second, count, res, i+1, i - idx +1, flag);
            if(flag)return;
            res.pop_back();
        }
    }
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        if(S.size()<3)return res;
        long long first, second;
        bool flag = false;
        for(int i = 0;i<S.size()-2;i++){
            for(int j=i+1;j<S.size()-1;j++){
                if(S.size() - 1 - j < max(i+1, j-i))continue;
                first = toInt(S, 0, i);
                second = toInt(S, i+1, j);
                if(first == -1||second == -1)continue;
                res.push_back(first);
                res.push_back(second);
                backtracking(S, first, second, res, j+1, max(i+1, j-i), flag);
                if(flag)return res;
                res.pop_back();
                res.pop_back();

            }
        }
        if(!flag)res.clear();
        return res;
    }
};


