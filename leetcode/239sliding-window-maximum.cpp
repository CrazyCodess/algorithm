/**
* @Date 2019/03/14 19:13
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int id1=0, id2=-1, count=0;
        
        deque<int> deq;
        vector<int> res;
        while(id1<nums.size()){
            if(count<k){
                if(id2 == nums.size()-1)break;
                id2++;
                deq.push_back(nums[id2]);
                count++;
            }
            if(count == k){
                priority_queue<int> que(deq.begin(), deq.end());
                res.push_back(que.top());
                deq.pop_front();
                id1++;
                count--;
            }
        }
        return res;
    }
};
int main(){
    Solution solu;
    vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
    vector<int> res = solu.maxSlidingWindow(nums,5);
    for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
    return 0;
}