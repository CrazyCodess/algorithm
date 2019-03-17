/**
* @Date 2019/03/02 10:15
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};

int main()
{
    Solution solu;
    vector<int> nums{1,1,1,2,2,3};
    cout<<solu.removeDuplicates(nums)<<"\n";
    for(int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
    return 0;
}
