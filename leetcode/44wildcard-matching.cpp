//
// Created by dell on 2019/1/20.
//

//
// Created by dell on 2018/12/22.
//
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        vector<vector<bool> > value(plen+1);
        for(int i=0;i<value.size();i++){
            value[i].resize(slen+1);
        }
        value[0][0] = true;
        for(int i = 1;i <= s.length();i++){
            value[0][i] = false;
        }
        for(int i = 1;i <= p.length(); i++){
            if(p[i-1] == '*'){
                value[i][0] = value[i-1][0];
                for(int j = 1;j <= s.length(); j++){
                    value[i][j] = (value[i][j-1] || value[i-1][j] || value[i-1][j-1]);
                }
            }else if(p[i-1] == '?'){
                value[i][0] = false;
                for(int j = 1;j <= s.length(); j++){
                    value[i][j] = value[i-1][j-1];
                }
            }else {
                value[i][0] = false;
                for(int j = 1;j <= s.length(); j++){
                    value[i][j] = s[j-1] == p[i-1] && value[i-1][j-1];
                }
            }

        }

        return value[p.length()][s.length()];
    }
};

