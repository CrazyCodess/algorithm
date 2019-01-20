//
// Created by dell on 2019/1/19.
//

//
// Created by dell on 2018/12/22.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bits(int num){
        int ans = 0;
        while(num){
            ans += num&1;
            num >>=1;
        }
        return ans;
    }
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0;i<=num;i++){
            res.push_back(bits(i));
        }
        return res;
    }
};

