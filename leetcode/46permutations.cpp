/**
* @Date 2019/2/14 16:40
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cnt = nums.size()-1;
        int tmp=0;
        while(cnt>=1&&nums[cnt]<=nums[cnt-1])cnt--;
        int l,r;
        if(cnt == 0){
            l = 0,r = nums.size()-1;
            while(l<r){
                tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
                l++;
                r--;
            }
        }else {
            l = cnt, r = nums.size()-1;
            tmp = cnt-1;
            while(cnt<nums.size()&&nums[cnt]>nums[tmp])cnt++;
            int tmp1 = nums[tmp];
            nums[tmp] = nums[cnt - 1];
            nums[cnt-1] = tmp1;
            while(l<r){
                tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
                l++;
                r--;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        while(true){
            int cnt = nums.size()-1;
            while(cnt>=1&&nums[cnt]>=nums[cnt-1])cnt--;
            if(cnt == 0)break;
            nextPermutation(nums);
        }
        while(true){
            ans.push_back(nums);
            int cnt = nums.size()-1;
            while(cnt>=1&&nums[cnt]<=nums[cnt-1])cnt--;
            if(cnt == 0)break;
            nextPermutation(nums);
        }
        return ans;
    }
};


