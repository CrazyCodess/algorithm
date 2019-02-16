/**
* @Date 2019/1/22 22:13
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.clear();

        int cnt = nums.size();
        if(cnt == 0)return ans;
        vector<int> tmp;
        tmp.clear();
        int bitCnt = 1;
        while(cnt--){
            bitCnt *=2;
        }
        for(int i=0;i<bitCnt;i++){
            bitset<10000> bits(i);
            tmp.clear();
            for(int j=0;j<bits.size();j++){
                if(bits[j])tmp.push_back(nums[j]);
            }
            ans.push_back(tmp);

        }
        return ans;
    }
};


