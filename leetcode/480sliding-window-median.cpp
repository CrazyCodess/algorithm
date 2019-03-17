/**
* @Date 2019/03/15 15:02
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int> &wins, int target){
        int left=0, right=wins.size()-1, mid ;
        while(left<=right){
            mid = (left+right)/2;
            if(wins[mid]>target)right = mid - 1;
            else if(wins[mid]<target)left = mid+1;
            else return mid;
        }
        return left;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        vector<int> wins(nums.begin(), nums.begin()+k);
        sort(wins.begin(), wins.end());
        res.push_back(((double)wins[k/2]+(double)wins[(k-1)/2])/2.0);
        int idx;
        for(int i=k;i<nums.size();i++){
            idx = binarySearch(wins, nums[i-k]);
           wins.erase(wins.begin()+idx);
           idx = binarySearch(wins, nums[i]);
           wins.insert(wins.begin()+idx, nums[i]);
           res.push_back(((double)wins[k/2]+(double)wins[(k-1)/2])/2.0);
        }
        return res;
    }
};

int main(){
    Solution solu;
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    vector<double> res;

    res = solu.medianSlidingWindow(nums, 3);
    for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
    //cout<<endl;
    return 0;
}