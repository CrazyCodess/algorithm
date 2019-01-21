/**
* @Date 2019/1/20 22:02
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int mid = len/2;
        int gap ;
        gap = abs(nums[0] + nums[1] + nums[2] - target);
        int sum = nums[0] + nums[1] + nums[2];
        int l,r;
        for(int i=0;i<len - 2;i++){
            l = i+1;
            r = len -1;
            while(l<r){
                int tmp = nums[i] + nums[l] + nums[r] - target;
                gap = abs(tmp);
                sum = nums[i] + nums[l] + nums[r];
                if(tmp<0){

                    l++;
                }else{
                    r--;
                }
            }

        }
        return sum;

    }
};


