/**
* @Date 2019/2/23 11:05
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
        }
        return count;
    }
    void backtracking(string &num, long long first, long long second, bool &flag, int idx, int w){
        if(idx>=num.size()){
            flag = true;
            return;
        }
        for(int i = idx;i<num.size();i++){
            if(i - idx +1 > w + 1)return;
            long long count = toInt(num, idx, i);
            if(count == -1)return;
            if(count != first + second)continue;
            backtracking(num, second, count, flag, i+1, i - idx +1);
        }
    }
    bool isAdditiveNumber(string num) {
        if(num.size()<3)return false;
        bool flag = false;
        long long first, second;
        for(int i = 0;i<num.size()-2;i++){
            for(int j=i+1;j<num.size()-1;j++){
                if(num.size() - 1 - j < max(i+1, j-i))continue;
                first = toInt(num, 0, i);
                second = toInt(num, i+1, j);
                if(first == -1||second == -1)continue;
                backtracking(num, first, second, flag, j+1, max(i+1, j-i));
                if(flag)return true;
            }
        }
        return false;
    }
};


