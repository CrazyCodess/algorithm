/**
* @Date 2019/2/19 9:36
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]+i>=n)
                n=i;
        }
        if(n==0)
            return true;
        else
            return false;
    }
};

