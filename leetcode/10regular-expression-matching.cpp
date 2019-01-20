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

    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        vector<vector<bool> > value(plen+3, vector<bool>(slen+3, false));
        value[0][0] = true;
        //for(int i=1;i<slen+1;i++)value[0][i] = false;
        value[1][1] = s[0] == p[0]||p[0] == '.';
        for(int j=2;j<=plen;j++){
            value[j][0] = value[j-2][0] && p[j-1] == '*';
        }
        for(int i=0;i<plen;i++)
            for(int j=0;j<slen;j++){
                if(p[i] == '*'){
                    value[i+1][j+1] = value[i-1][j+1]||value[i+1][j]&&(p[i-1] == s[j]||p[i-1] == '.');
                }else{
                    value[i+1][j+1] = value[i][j]&&(p[i]==s[j]||p[i] == '.');
                }
            }

        return value[plen][slen];
    }
};







