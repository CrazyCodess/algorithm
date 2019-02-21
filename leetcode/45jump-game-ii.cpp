/**
* @Date 2019/2/19 9:56
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n, INT_MAX);
        steps[0] = 0;
        int range = 0;
        for(int i=0;i<n - 1;i++){
            if(range == n-1)break;
            if(i+nums[i]<=range)continue;
            for(int j = range-i+1;j<=nums[i]&&(i+j)<n;j++){
                if(steps[i]+1 < step[i+j])steps[i+j] = steps[i] + 1;
            }
            range = min(n-1, i+nums[i]);
        }
        return steps[n-1];
    }
};


