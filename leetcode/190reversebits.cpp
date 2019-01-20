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
    uint32_t reverseBits(uint32_t n) {
        int i = 32;
        uint32_t ans = 0;
        while (i--){
            ans <<=1;
            ans += n&1;
            n>>=1;
        }
        return ans;
    }
};


