/**
* @Date 2019/2/19 11:04
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')return 0;
        if(s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
        if(s.size() == 1) return 1;
        vector<int> nums(s.size()+1, 0);
        nums[0] = 1;
        for(int i = 0;i<s.size();i++){
            nums[i+1] = s[i] == '0'?0:nums[i];
            if(i>0){
                if(s[i-1] == '1'||(s[i-1] == '2'&&s[i]<='6'))
                    nums[i+1] += nums[i-1];
            }
        }
        return nums[s.size()];
    }
};

