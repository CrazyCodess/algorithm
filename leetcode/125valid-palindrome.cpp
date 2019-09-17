#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if(n == 0)return true;
        string res;
        for(int i = 0;i < n;i++){
            if((s[i]>='A' && s[i] <= 'Z')||(s[i]>='a' && s[i] <= 'z')||(s[i]>='0' && s[i] <= '9')){
                res.push_back(tolower(s[i]));
            }
        }
        n = res.size();
        if(n == 0)return true;
        int l = 0, r = n - 1;
        while(l <= r){
            if(res[l] != res[r])return false;
            l++;
            r--;
        }
        return true;
    }
};