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
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int i=0;i<12;i++){
            bitset<4> hour(i);
            for(int j=0;j<60;j++){
                bitset<6> min(j);
                if(hour.cout() + min.count()==num){
                    res.push_back(to_string(i)+(j<10?":0":":")+to_string(j));
                }
            }
        }
    }
};


