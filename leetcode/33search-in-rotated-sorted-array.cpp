/**
* @Date 2019/1/22 16:01
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)return -1;
        if(nums[0] == target)return 0;
        if(nums.size()<=1)return -1;
        if(nums[1] == target)return 1;
        if(nums.size()<=2)return -1;
        int l = 0,h = nums.size()-1,mid;
        while(l<h){
            if(nums[l] == target)return l;
            if(nums[h] == target)return h;
            mid = (l+h+1)/2;
            if(nums[mid] == target)return mid;

            if(nums[mid]>=nums[l]){
                if(target>nums[l]&&target<nums[mid])h = mid-1;
                else l = mid+1;
            }else{
                if(target>nums[mid]&&target<nums[h])l = mid+1;
                else h = mid-1;
            }
        }
        return -1;
    }
};


