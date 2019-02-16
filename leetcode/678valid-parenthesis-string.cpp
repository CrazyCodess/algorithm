/**
* @Date 2019/2/16 15:50
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int c1=0, c2=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ')'){
                c1--;
                c2 = max(c2-1, 0);
            }else if(s[i] == '('){
                c1++;
                c2++;
            }else{
                c1++;
                c2 = max(c2-1, 0);
            }
            if(c1<0)return false;
        }
        return c2==0;
    }
};


