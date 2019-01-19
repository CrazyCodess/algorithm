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
    string convert(string s, int numRows) {
        if(numRows <=1)return s;
        string res;
        int n = numRows;
        int index = 0;
        bool flag = true;
        for(int i=0;i<n;i++){

            index = i;
            flag = true;
            if(i ==0||i==n-1){
                while(index<s.length()){
                    res += s[index];
                    index += 2*n-2;
                }
            }else{
                while(index < s.length()){
                    res += s[index];
                    if(flag){
                        index += 2*n-2-i*2;
                        flag = false;
                    }else{
                        index += i*2;
                        flag = true;
                    }
                }
            }

        }
        return res;
    }
};


