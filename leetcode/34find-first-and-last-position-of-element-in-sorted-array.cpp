/**
* @Date 2019/2/14 22:19
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if(nums.size()==1){
            if(target == nums[0]){
                ans[0] = 0;
                ans[1] = 0;
            }
            return ans;
        }

        int start =-1,end = -1;
        int l = 0,r = nums.size()-1;
        int mid;
        while(l<r) {
            mid = (l + r) / 2;
            if (nums[mid] == target)break;
            if (nums[mid] < target)l = mid + 1;
            else r = mid - 1;
        }
        if(l == r&&nums[l] == target){
            ans[0] = l;
            ans[1] = l;
            return ans;
        }
        if(l>=r)return ans;
        start = l;
        end = mid;
        int m = -1;
        while(start<end){
            m = (start + end)/2;
            if(nums[start] == target)break;
            if(nums[m]<target)start = m+1;
            else end = m;
        }
        ans[0] = start;
        start = mid;
        end = r;
        while(start<end){
            m = (start + end+1)/2;
            if(nums[end] == target)break;
            if(nums[m]>target)end = m-1;
            else start = m;
        }
        ans[1] = end;
        return ans;
    }
};


