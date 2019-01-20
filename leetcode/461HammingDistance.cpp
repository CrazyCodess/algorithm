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
    int hammingWeight(int n) {
        int ans = 0;
        while(n){
            ans += n&1;
            n>>=1;
        }
        return ans;
    }
    int hammingDistance(int x, int y) {
        return hammingWeight(x)+hammingWeight(y) - 2*hammingWeight(x&y);
    }
};

